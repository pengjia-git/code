import cv2
import numpy as np
img=cv2.imread("./dog.jpg")
logo=cv2.imread("./xiaomi_logo.jpeg")
logoHeight=logo.shape[0]
columnStart=img.shape[1]-logo.shape[1]
img[0:logoHeight,columnStart:img.shape[1]]=logo
t=np.zeros((10,1),np.uint8)
print(t[0:3])
cv2.imshow("img",img)
cv2.waitKey(0)