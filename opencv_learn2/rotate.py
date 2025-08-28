import cv2
import numpy as np

# 读取图像
image = cv2.imread('/Users/pengjia/work/opencv_learn/dog.jpg')  # 替换为你的图片路径
if image is None:
    print("错误：无法加载图像！")
    exit()

# 获取图像尺寸
(h, w) = image.shape[:2]

# 设置旋转参数
angle = 15  # 顺时针旋转30度
# center = (w // 2, h // 2)  # 旋转中心（图像中心）
center=(0,0)
scale = 1.0  # 缩放比例（1.0表示不缩放）

# 计算旋转矩阵（OpenCV使用逆时针为正方向，所以用负角度表示顺时针）
rotation_matrix = cv2.getRotationMatrix2D(center, angle, scale)
print(rotation_matrix)

# 计算旋转后的图像尺寸（避免裁剪）
cos = np.abs(rotation_matrix[0, 0])
sin = np.abs(rotation_matrix[0, 1])
new_w = int((h * sin) + (w * cos))
new_h = int((h * cos) + (w * sin))

# 调整旋转矩阵的平移部分（使图像居中）
rotation_matrix[0, 2] += (new_w / 2) - center[0]
rotation_matrix[1, 2] += (new_h / 2) - center[1]

# 应用仿射变换
# rotated_image = cv2.warpAffine(image, rotation_matrix, (new_w, new_h))
rotated_image = cv2.warpAffine(image, rotation_matrix, (w,h))

# 显示结果
cv2.imshow('Original Image', image)
cv2.imshow('Rotated Image (30 degrees clockwise)', rotated_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

# 可选：保存旋转后的图像
# cv2.imwrite('rotated_image.jpg', rotated_image)