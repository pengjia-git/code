
import cv2
import numpy as np

oriImg=cv2.imread("./hand.jpg")
# 转换为HSV颜色空间
hsv = cv2.cvtColor(oriImg, cv2.COLOR_BGR2HSV)
# 定义白色的HSV范围
lower_white = np.array([0, 0, 200], dtype=np.uint8)
upper_white = np.array([180, 30, 255], dtype=np.uint8)
# 生成白色区域的掩码
mask = cv2.inRange(hsv, lower_white, upper_white)
# 将白色背景改为黑色
oriImg[mask > 0] = [0, 0, 0]  # BGR格式的黑色

#将图像转换为灰度图像
grayImg=cv2.cvtColor(oriImg,cv2.COLOR_BGR2GRAY)

#二值化
ret,binImg=cv2.threshold(grayImg,30,255,cv2.THRESH_BINARY)

#闭运算
kernel=np.ones((3,3),np.uint8)
binImg=cv2.morphologyEx(binImg,cv2.MORPH_CLOSE,kernel)

#查找轮廓
contours,hierarchy=cv2.findContours(binImg,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)

for i in range(len(contours)):
    #每按一次按键，就画一个轮廓
    print("第"+str(i)+"个轮廓的坐标点：")
    cv2.drawContours(oriImg,contours,i,(0,255,0),1)
    len=cv2.arcLength(contours[i],True)
    approx=cv2.approxPolyDP(contours[i],len*0.005,True)
    cv2.drawContours(oriImg,[approx],i,(255,0,0),1)
    cv2.imshow("drawImg",oriImg)

    cv2.waitKey(0)