import cv2
import numpy as np

oriImg=cv2.imread("./dog.jpg")
hsvImg=cv2.cvtColor(oriImg,cv2.COLOR_BGR2HSV)
#将明亮度往上加50
hsvImg[:,:,2]=cv2.add(hsvImg[:,:,2],20)
#将hsv图像转换回bgr图像
bgrImg=cv2.cvtColor(hsvImg,cv2.COLOR_HSV2BGR)
#展示原始的图片
cv2.imshow("oriImg",oriImg)
cv2.imshow("bgrImg",bgrImg)
cv2.waitKey(0)