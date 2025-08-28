
import cv2
import numpy as np

oriImg=cv2.imread("./building.jpeg")
#转换成hsv
hsvImg=cv2.cvtColor(oriImg,cv2.COLOR_BGR2HSV)
#去掉蓝色背景
lower_blue=np.array([100,43,46])
upper_blue=np.array([124,255,255])
mask=cv2.inRange(hsvImg,lower_blue,upper_blue)

# 将白色背景改为黑色
oriImg[mask > 0] = [0, 0, 0]  # BGR格式的黑色

#去掉红色背景
lower_red1 = np.array([0, 20, 20])     # 0°～10°
upper_red1 = np.array([10, 255, 255])
lower_red2 = np.array([170, 20, 20])   # 170°～180°
upper_red2 = np.array([180, 255, 255])
mask1 = cv2.inRange(hsvImg, lower_red1,upper_red1)
mask2 = cv2.inRange(hsvImg, lower_red2,upper_red2)
oriImg[mask1 > 0] = [0, 0, 0]  
oriImg[mask2 > 0] = [0, 0, 0]  
cv2.imshow("oriImg",oriImg)

cv2.waitKey(0)
#转换为灰度图像
grayImg=cv2.cvtColor(oriImg,cv2.COLOR_BGR2GRAY)
cv2.imshow("grayImg",grayImg)

#二值化
ret,binImg=cv2.threshold(grayImg,30,255,cv2.THRESH_BINARY)
cv2.imshow("binImg",binImg)

cv2.waitKey(0)
cv2.destroyAllWindows()