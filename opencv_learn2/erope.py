
import cv2
import numpy as np

oriImg=cv2.imread("./font1.jpg")
grayImg=cv2.cvtColor(oriImg,cv2.COLOR_BGR2GRAY)
ret,binImg=cv2.threshold(grayImg,127,255,cv2.THRESH_BINARY_INV)
kernel=np.ones((3,3),np.uint8)
dilateImg=cv2.dilate(binImg,kernel,iterations=1)
eropeImg=cv2.erode(dilateImg,kernel,iterations=1)
#展示原始的图片
cv2.imshow("oriImg",binImg)
cv2.imshow("eropeImg",eropeImg)
cv2.imshow("dilateImg",dilateImg)
cv2.waitKey(0)