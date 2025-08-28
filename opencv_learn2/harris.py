import cv2
import numpy as np

# 读取图像并转为灰度
img = cv2.imread("./chess_board.jpeg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Harris 角点检测
gray = np.float32(gray)  # 输入需为 float32
block_size = 2      # 窗口大小
ksize = 3           # Sobel 核大小
k = 0.04            # Harris 参数
dst = cv2.cornerHarris(gray, block_size, ksize, k)

# 标记角点
dst = cv2.dilate(dst, None)  # 膨胀增强角点

print(dst)
img[dst > 0.01 * dst.max()] = [0, 255, 0]  # 阈值筛选并标红

cv2.imshow("Harris Corners", img)
cv2.waitKey(0)