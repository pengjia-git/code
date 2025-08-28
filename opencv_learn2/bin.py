
import cv2
import numpy as np

oriImg=cv2.imread("./dog.jpg")
grayImg=cv2.cvtColor(oriImg,cv2.COLOR_BGR2GRAY)
ret,binImg=cv2.threshold(grayImg,200,255,cv2.THRESH_BINARY)
cv2.imshow("oriImg",oriImg)
cv2.imshow("grayImg",grayImg)
cv2.imshow("binImg",binImg)
cv2.waitKey(0)
cv2.destroyAllWindows()