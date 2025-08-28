import cv2;

img=cv2.imread("./test.jpeg",cv2.IMREAD_REDUCED_GRAYSCALE_2)
#copy img
img2=img.copy()

#获取img的 size字段

#获取img的宽度
width=img.shape[1]
print(img.shape)
print(img.size)
print(img.dtype)
cv2.imshow("img",img)
#img2 的第100行的所有像素点赋值为[0,0]
img2[100,:width]=128
cv2.imshow("img2",img2)

cv2.waitKey(0)
cv2.destroyAllWindows()