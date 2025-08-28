import cv2
import numpy as np

def apply_convolution(image_path, kernel, output_path=None):
    """
    对图像应用卷积操作
    
    参数:
        image_path: 输入图像路径
        kernel: 卷积核(2D numpy数组)
        output_path: 输出图像保存路径(可选)
    """
    # 读取图像
    img = cv2.imread(image_path)
    if img is None:
        print("无法加载图像，请检查路径")
        return
    
    # 应用卷积
    result = cv2.filter2D(img, -1, kernel)
    
    # 显示原图和结果
    cv2.imshow('Original Image', img)
    cv2.imshow('Convolution Result', result)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
    # 如果需要保存结果
    if output_path:
        cv2.imwrite(output_path, result)
        print(f"结果已保存到 {output_path}")

# 示例卷积核
# 1. 均值模糊核
blur_kernel = np.ones((5, 5), np.float32) / 25

# 2. 高斯模糊核
gaussian_kernel = np.array([
    [1, 2, 1],
    [2, 4, 2],
    [1, 2, 1]
], np.float32) / 16

# 3. 边缘检测核 (Sobel水平)
sobel_x_kernel = np.array([
    [-1, 0, 1],
    [-2, 0, 2],
    [-1, 0, 1]
], np.float32)

# 4. 边缘检测核 (Sobel垂直)
sobel_y_kernel = np.array([
    [-1, -2, -1],
    [0, 0, 0],
    [1, 2, 1]
], np.float32)

# 5. 拉普拉斯边缘检测核
laplacian_kernel = np.array([
    [0, 1, 0],
    [1, -4, 1],
    [0, 1, 0]
], np.float32)

# 6. 锐化核
sharpen_kernel = np.array([
    [0, -1, 0],
    [-1, 5, -1],
    [0, -1, 0]
], np.float32)

# 使用示例
if __name__ == "__main__":
    image_path = 'face1.jpg'  # 替换为你的图像路径
    
    print("1. 应用均值模糊")
    apply_convolution(image_path, blur_kernel, 'blur_result.jpg')
    
    print("\n2. 应用高斯模糊")
    apply_convolution(image_path, gaussian_kernel, 'gaussian_result.jpg')
    
    print("\n3. 应用水平Sobel边缘检测")
    apply_convolution(image_path, sobel_x_kernel, 'sobel_x_result.jpg')
    
    print("\n4. 应用垂直Sobel边缘检测")
    apply_convolution(image_path, sobel_y_kernel, 'sobel_y_result.jpg')
    
    print("\n5. 应用拉普拉斯边缘检测")
    apply_convolution(image_path, laplacian_kernel, 'laplacian_result.jpg')
    
    print("\n6. 应用锐化")
    apply_convolution(image_path, sharpen_kernel, 'sharpen_result.jpg')