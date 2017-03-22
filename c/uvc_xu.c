#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <linux/usb/ch9.h>
#include <linux/usb/video.h>
#include <linux/videodev2.h>
#include <linux/uvcvideo.h>
#define DBG_LOG
#ifdef DBG_LOG
#define uvc_printf(msg...)			\
  printf("[uvc]" msg)
#else
#define uvc_printf(...)
#endif


struct buffer {
  void *start;
  size_t length;
};

struct camera {
  char *device_name;
  int fd;
  int width;
  int height;
  int display_depth;
  int image_size;
  int frame_number;
  struct v4l2_capability v4l2_cap;
  struct v4l2_cropcap v4l2_cropcap;
  struct v4l2_format v4l2_fmt;
  struct v4l2_crop crop;
  struct buffer *buffers;
};
void init_mmap(struct camera *cam);
void start_capturing(struct camera *cam);
void init_file() ;
void close_file();
void capture_data_thread(void);
int read_one_frame(struct camera *cam) ;
int send_xu_cmd(int fd, unsigned char xu_unit, unsigned char xu_selector,unsigned char xu_query,
		unsigned char xu_size,unsigned char *xu_data);
struct camera *cam;
unsigned int n_buffers = 0;

int main()
{
  unsigned char cmd_param_buf[64];
  cam = (struct camera *) malloc(sizeof(struct camera));
  cam->device_name = "/dev/video0";
  cam->buffers = NULL;
  
  //char *devname="/dev/video0";
  struct stat st;
  struct uvc_device *dev;
  struct v4l2_capability cap;
  int ret;

  struct v4l2_fmtdesc fmtdesc;
  struct v4l2_format fmt;

  int i;

  while ((cam->fd = open(cam->device_name, O_RDWR)) < 0)
    {
      perror("failed!!");
      printf("cam->fd=%d uvc device node is not ready! sleep 30ms\n",cam->fd);
    }
  printf("open success\n");

  ret = ioctl(cam->fd, VIDIOC_QUERYCAP, &cap);
  if (ret < 0)
    {
      // uvc_printf("unable to query device: %s (%d)\n", strerror(errno), errno);
      close(cam->fd);
      return 0;
    }

  if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)) {
    uvc_printf("No V4L2_CAP_VIDEO_CAPTURE \n");
  }

  if (!(cap.capabilities & V4L2_CAP_STREAMING)) {
    uvc_printf("No V4L2_CAP_STREAMING \n");
  }
  uvc_printf("device is %s on bus %s\n", cap.card, cap.bus_info);

  /*memset(&fmtdesc,0,sizeof(fmtdesc));
    fmtdesc.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmtdesc.index=0;
    while( (ret=ioctl(cam->fd,VIDIOC_ENUM_FMT,&fmtdesc)) == 0){
    fmtdesc.index++;
    printf("format fourcc=%s\n",(char *)(&fmtdesc.pixelformat));
    }
    printf(" fmtdesc.index=%d\n", fmtdesc.index);*/

  memset(&fmt,0,sizeof(fmt));
  fmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
  fmt.fmt.pix.width=1280;//640;
  fmt.fmt.pix.height=720;//480;
  fmt.fmt.pix.pixelformat=V4L2_PIX_FMT_H264;//V4L2_PIX_FMT_YUYV;//V4L2_PIX_FMT_MJPEG;//V4L2_PIX_FMT_H264;//V4L2_PIX_FMT_YUYV;
  fmt.fmt.pix.field=V4L2_FIELD_ANY;//V4L2_FIELD_NONE
#if 1
  ret=ioctl(cam->fd,VIDIOC_TRY_FMT,&fmt);
 
  if(ret){
    printf("try format fail ret=%d\n",ret);
    return 0;
  }
  else{
    printf("set format success width=%d,height=%d foxmat=%x\n",fmt.fmt.pix.width,fmt.fmt.pix.height,fmt.fmt.pix.pixelformat);
  }
#endif
//  ioctl(cam->fd,VIDIOC_G_FMT,&fmt);
//  if(ret){
//    printf("get format fail ret=%d\n",ret);
//    return 0;
//  }
//  else{
//    printf("get format success width=%d,height=%d %x\n",fmt.fmt.pix.width,fmt.fmt.pix.height,fmt.fmt.pix.pixelformat);
//  }
//  cam->width=fmt.fmt.pix.width;
//  cam->height=fmt.fmt.pix.height;

  //扩展指令
  int fail_count=0;
	for (i = 0; i < 100; i++)
	{
		int cmd=80;
		for(;cmd<83;cmd++){
		int count=0;

		memset(cmd_param_buf, 0, 64);
		cmd_param_buf[0] = cmd;

		do{
			ret = send_xu_cmd(cam->fd, 4, 0x0c, UVC_SET_CUR, 64, cmd_param_buf);
		}while(ret != 0);
		usleep(500 * 1000);
		memset(cmd_param_buf, 0, 64);
		do
		{
			usleep(10 * 1000);
			//printf("count=%d\n",count++);
			ret = send_xu_cmd(cam->fd, 4, 0x0c, UVC_GET_CUR, 64, cmd_param_buf);
		} while (ret == -1 );

//		printf("%d ,%d \n", cmd_param_buf[0], cmd_param_buf[1]);
//		printf("ret=%d\n", ret);
		if(cmd_param_buf[0] != cmd ||   cmd_param_buf[1] != 1){
			printf("cmd=%d %d ,%d \n", cmd,cmd_param_buf[0], cmd_param_buf[1]);
			fail_count++;
			//break;
		}

//		send_xu_cmd(cam->fd, 4, 0x0c, UVC_GET_CUR, 64, cmd_param_buf);
		}
	}
	printf("i=%d fail_count=%d\n",i,fail_count);
  //close_file();
  close(cam->fd);
  return 0;
}
//vidioc_enum_fmt_cap VIDIOC_ENUM_FMT

#define CLEAR(x) memset (&(x), 0, sizeof (x))

int xioctl(int fd, int request, void *arg) {
  int r = 0;
  do {
    r = ioctl(fd, request, arg);
  } while (-1 == r && EINTR == errno);

  return r;
}

void init_mmap(struct camera *cam)
{
  struct v4l2_requestbuffers req;
  int ret;
  CLEAR(req);

  req.count = 4;
  req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  req.memory = V4L2_MEMORY_MMAP;

  ret=ioctl(cam->fd, VIDIOC_REQBUFS, &req);
  if(ret){
    printf("get memory faile\n");
    return ;
  }
  

  if (req.count < 2) {
    printf("memory is not enough\n");
    return ;
  }

  cam->buffers = calloc(req.count, sizeof(*(cam->buffers)));

  if (!cam->buffers) {
    fprintf(stderr, "Out of memory\n");
    return;
  }

  for (n_buffers = 0; n_buffers < req.count; ++n_buffers) {
    struct v4l2_buffer buf;

    CLEAR(buf);

    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    buf.index = n_buffers;

    //将VIDIOC_REQBUFS中分配的数据缓存转换成物理地址
    if (-1 == xioctl(cam->fd, VIDIOC_QUERYBUF, &buf)){
      printf("VIDIOC_QUERYBUF fail\n");
      return;
    }

    cam->buffers[n_buffers].length = buf.length;
    cam->buffers[n_buffers].start = mmap(NULL /* start anywhere */,
					 buf.length, PROT_READ | PROT_WRITE /* required */,
					 MAP_SHARED /* recommended */, cam->fd, buf.m.offset);

    if (MAP_FAILED == cam->buffers[n_buffers].start){
      printf("MAP_FAILED\n");
      return;
    }
  }

  printf("get memory success\n");
}

void start_capturing(struct camera *cam) {
  unsigned int i;
  enum v4l2_buf_type type;

  for (i = 0; i < n_buffers; ++i) {
    struct v4l2_buffer buf;

    CLEAR(buf);

    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    buf.index = i;

    if (-1 == xioctl(cam->fd, VIDIOC_QBUF, &buf))
      printf("VIDIOC_QBUF");
  }

  type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

  if (-1 == xioctl(cam->fd, VIDIOC_STREAMON, &type))
    printf("VIDIOC_STREAMON");

}

char yuv_file_name[100] = "usb_host.h264";
//char yuv_file_name[100] = "usb_host.mjpeg";

FILE *yuv_fp;

void init_file() 
{
  //	h264_fp = fopen(h264_file_name, "wa+");
  yuv_fp = fopen(yuv_file_name, "wa+");
}

void close_file() {
  //	fclose(h264_fp);
  fclose(yuv_fp);
}


void capture_data_thread(void) {
  int count = 1;
  for (;;) {
    printf("-->this is the %dth frame\n", count);
    if (count++ >= 100) // 采集100帧的数据
      {
	printf("------need to exit from thread------- \n");
	break;
      }

    fd_set fds;
    struct timeval tv;
    int r;

    FD_ZERO(&fds);
    FD_SET(cam->fd, &fds);

    /* Timeout. */
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    r = select(cam->fd + 1, &fds, NULL, NULL, &tv);
    printf("r=%d\n",r);

    if(FD_ISSET(cam->fd,&fds)){
      read_one_frame(cam);
    }
    /*if (read_one_frame(cam) != 1) {
      fprintf(stderr, "read_fram fail in thread\n");
      break;
      }*/
  }
}


int read_one_frame(struct camera *cam) {
  struct v4l2_buffer buf;

  //printf("in read_frame\n");

  CLEAR(buf);

  buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  buf.memory = V4L2_MEMORY_MMAP;

  //this operator below will change buf.index and (0 <= buf.index <= 3)
  if (-1 == xioctl(cam->fd, VIDIOC_DQBUF, &buf)) {
    printf("VIDIOC_DQBUF error\n");
  }

  //encode_frame(cam->buffers[buf.index].start, buf.length);
  printf("buf.index=%d\n",buf.index);
  printf("buf.bytesused=%d\n",buf.bytesused);
  fwrite(cam->buffers[buf.index].start, buf.bytesused, 1, yuv_fp);
  if (-1 == xioctl(cam->fd, VIDIOC_QBUF, &buf))
    printf("VIDIOC_QBUF");

  return 1;
}

int send_xu_cmd(int fd, unsigned char xu_unit, unsigned char xu_selector,unsigned char xu_query,
		unsigned char xu_size,unsigned char *xu_data)
{
  int err=0;
  struct uvc_xu_control_query xctrl;
  xctrl.unit =xu_unit;
  xctrl.selector=xu_selector;
  xctrl.query=xu_query;//UVC_SET_CUR;
  xctrl.size=xu_size;
  xctrl.data=xu_data;
  err=ioctl(fd,UVCIOC_CTRL_QUERY,&xctrl);
  return err;
}
