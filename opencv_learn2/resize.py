
import cv2
import numpy as np

img=cv2.imread("./xiaomi_logo.jpeg")
img2=cv2.resize(img,(0,0),fx=2,fy=2)
img3=cv2.resize(img,(0,0),fx=2,fy=2,interpolation=cv2.INTER_AREA)
cv2.imshow("img2",img2)
cv2.imshow("img3",img3)
cv2.waitKey(0)