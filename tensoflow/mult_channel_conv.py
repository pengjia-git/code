import tensorflow as tf
import numpy as np

x1=tf.constant([[0,1,2],[3,4,5]])
x2=tf.constant([[6,7,8],[9,10,11]])
x3=tf.constant([[12,13,14],[15,16,17]])
z=tf.stack([x1,x2,x3],axis=-1)
print(z)
exit()

# 创建一个简单的RGB图像 (6x8像素，3个通道)
# 红色通道: 左右边缘为1，中间为0
red_channel = tf.ones((6, 8))
red_channel = tf.Variable(red_channel)
red_channel[:, 2:6].assign(tf.zeros(red_channel[:, 2:6].shape))

# 绿色通道: 上下边缘为1，中间为0
green_channel = tf.ones((6, 8))
green_channel = tf.Variable(green_channel)
green_channel[2:4, :].assign(tf.zeros(green_channel[2:4, :].shape))

# 蓝色通道: 对角线条纹
blue_channel = tf.zeros((6, 8))
for i in range(6):
    for j in range(8):
        if (i + j) % 2 == 0:
            blue_channel[i, j].assign(1.0)

# 组合成RGB图像 (6, 8, 3)
rgb_image = tf.stack([red_channel, green_channel, blue_channel], axis=-1)
rgb_image = tf.reshape(rgb_image, (1, 6, 8, 3))  # 添加批次维度

print("RGB图像形状:", rgb_image.shape)
print("红色通道:")
print(rgb_image[0, :, :, 0].numpy())
print("\n绿色通道:")
print(rgb_image[0, :, :, 1].numpy())
print("\n蓝色通道:")
print(rgb_image[0, :, :, 2].numpy())

# 定义多通道卷积核
# 使用3个不同的卷积核，每个核都有3个输入通道
# 卷积核形状: (高度, 宽度, 输入通道数, 输出通道数)
kernels = tf.constant([
    # 水平边缘检测核 (3个输入通道，1个输出通道)
    [[[-1, 1]], [[-1, 1]], [[-1, 1]]],
    
    # 垂直边缘检测核 (3个输入通道，1个输出通道)
    [[[-1], [1]], [[-1], [1]], [[-1], [1]]],
    
    # 对角线边缘检测核 (3个输入通道，1个输出通道)
    [[[-1, 0], [0, 1]], [[-1, 0], [0, 1]], [[-1, 0], [0, 1]]]
], dtype=tf.float32)

# 调整形状为 (高度, 宽度, 输入通道, 输出通道)
kernels = tf.transpose(kernels, [1, 2, 3, 0])
print("\n卷积核形状:", kernels.shape)

# 应用多通道卷积
output = tf.nn.conv2d(rgb_image, kernels, strides=1, padding='VALID')
print("输出形状:", output.shape)  # (批次, 高度, 宽度, 输出通道数)

# 显示每个输出通道的结果
print("\n水平边缘检测结果 (通道0):")
print(output[0, :, :, 0].numpy())

print("\n垂直边缘检测结果 (通道1):")
print(output[0, :, :, 1].numpy())

print("\n对角线边缘检测结果 (通道2):")
print(output[0, :, :, 2].numpy())