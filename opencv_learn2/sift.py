import cv2
import numpy as np
# 读取图像并转为灰度
img = cv2.imread("./chess_board.jpeg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# SIFT 特征检测
sift = cv2.SIFT_create()
keypoints= sift.detect(gray, None)
for k in keypoints:
    print(k.pt)
    print(k.size)

# 绘制关键点
img_with_keypoints = cv2.drawKeypoints(gray, keypoints, None, flags=cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
# 显示结果
cv2.imshow("SIFT Keypoints", img_with_keypoints)
cv2.waitKey(0)