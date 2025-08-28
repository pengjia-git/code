import cv2
import numpy as np

# 读取图像
image = cv2.imread('/Users/pengjia/work/opencv_learn/dog.jpg')  # 替换为你的图片路径
M = np.float32([[1, 0, 100], [0, 1, 0]])

# 应用仿射变换
shifted_image = cv2.warpAffine(image, M, (image.shape[1], image.shape[0]))
# 显示原始图像和平移后的图像
cv2.imshow('Original Image', image)
cv2.imshow('Shifted Image', shifted_image)
cv2.waitKey(0)