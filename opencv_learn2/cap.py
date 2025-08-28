import cv2
import numpy as np

#读取摄像头数据并显示出来
win=cv2.namedWindow("win",cv2.WINDOW_AUTOSIZE)
cap=cv2.VideoCapture(0)
while True:
    ret,frame=cap.read()
    frame=cv2.flip(frame,1)
    # frame=cv2.rotate(frame,cv2.ROTATE_90_CLOCKWISE)
    cv2.imshow("win",frame)
    key=cv2.waitKey(1)
    if key & 0xFF == ord('q'):
        break
cv2.destroyAllWindows() 
cap.release()