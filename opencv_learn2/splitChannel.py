import cv2;

img=cv2.imread("./test.jpeg")
mat1=img[:,:,0]
mat2=img[:,:,1]
mat3=img[:,:,2]
cv2.imshow("mat1",mat1)
cv2.imshow("mat2",mat2)
cv2.imshow("mat3",mat3)
print(mat3.shape)
cv2.waitKey(0)
cv2.destroyAllWindows()