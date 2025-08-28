import cv2
import numpy as np

# a=np.array([[1,2,3,4,5],[2,3,4,5,6]])
# print(a[1][0])

b=np.zeros((480,640,3),np.uint8)
count=0
while count < 480:
    b[count][100]=[0,0,255]
    count+=1

cv2.imshow("b",b)
cv2.waitKey(0)