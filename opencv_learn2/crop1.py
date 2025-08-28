import cv2
import numpy as np
#写一个opencv 窗口展示
win=cv2.namedWindow("win",cv2.WINDOW_NORMAL)
# cv2.resizeWindow("win",640,360)
cap=cv2.VideoCapture("./draw.mp4")
#打印cap的分辨率
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))  # 或者使用 cap.get(3)
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))  # 或者使用 cap.get(4:w
print(width)
print(height)
while True:
    ret,frame=cap.read()
    # cv2.imshow("win",frame)
    # 这是视频是576*1024，其中高度1024实际上是三个342高度重复拼接在一起的。所以把他去掉。
    newFrame=np.zeros((342,width,3),np.uint8)
    for i in range(342):
        for j in range(width):
            newFrame[i][j]=frame[i][j]
    cv2.imshow("newFrame",newFrame)
    key=cv2.waitKey(1)
    if key & 0xFF == ord('q'):
        break
cv2.destroyAllWindows()