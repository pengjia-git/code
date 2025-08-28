import cv2;

img=cv2.imread("./test.jpeg")
b,g,r=cv2.split(img)
b[:,:]=255
img2=cv2.merge((b,g,r))
cv2.imshow("img2",img2)
cv2.waitKey(0)
cv2.destroyAllWindows()