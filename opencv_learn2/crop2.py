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
    # 比一个一个像素点赋值快很多
    # newFrame=frame[0:342,:]
    newFrame=frame[0:342,0:288]
    # 增加一条拦腰线，学习用
    newFrame[171,:]=[0,0,255]
    cv2.imshow("newFrame",newFrame)
    key=cv2.waitKey(20)
    if key & 0xFF == ord('q'):
        break
cv2.destroyAllWindows()