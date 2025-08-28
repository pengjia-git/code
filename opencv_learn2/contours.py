
import cv2
import numpy as np

oriImg=cv2.imread("./contours.png")
grayImg=cv2.cvtColor(oriImg,cv2.COLOR_BGR2GRAY)
#二值化
ret,binImg=cv2.threshold(grayImg,127,255,cv2.THRESH_BINARY)
#对binImg 进行开运算
kernel=np.ones((3,3),np.uint8)
binImg=cv2.morphologyEx(binImg,cv2.MORPH_OPEN,kernel)
#查找轮廓
contours,hierarchy=cv2.findContours(binImg,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

#在一个同样尺寸的画布上绘制轮廓
drawImg=np.zeros_like(oriImg)
#把坐标点打印出来
for i in range(len(contours)):
    #每按一次按键，就画一个轮廓
    print("第"+str(i)+"个轮廓的坐标点：")
    # print(contours[i])
    #print(cv2.contourArea(contours[i]))
    len=cv2.arcLength(contours[i],True)
    if len < 100:
        continue
    # print(cv2.arcLength(contours[i],True))
    #画出轮廓i 
    # cv2.polylines(drawImg, [contours[i]], isClosed=True, color=(0, 255, 0), thickness=1)
    cv2.drawContours(drawImg,contours,i,(0,255,0),1)
    cv2.imshow("drawImg",drawImg)
    cv2.waitKey(0)