import tensorflow as tf
import numpy as np

# 自动处理权重/偏置/初始化
conv_layer = tf.keras.layers.Conv2D(
    filters=16,
    kernel_size=3,
    activation='relu',
    padding='same'
)

input_data = tf.random.normal([16, 32, 32, 1])  # 模拟输入
output = conv_layer(input_data)
print(output.shape)  # (1, 32, 32, 4)
#print("形状:", conv_layer.kernel.shape)
z=tf.keras.layers.AvgPool2D(pool_size=4, strides=4)(input_data)
print(z.shape)
exit()

# 创建一个简单的RGB图像 (6x8像素，3个通道)
# 红色通道: 左右边缘为1，中间为0
red_channel = tf.ones((6, 8))
red_channel = tf.Variable(red_channel)
red_channel[:, 2:6].assign(tf.zeros(red_channel[:, 2:6].shape))

# 绿色通道: 上下边缘为1���中间为0
green_channel = tf.ones((6, 8))
green_channel = tf.Variable(green_channel)
green_channel[2:4, :].assign(tf.zeros(green_channel[2:4, :].shape))

# 蓝色通道: 对角线条纹
rows, cols = 6, 8
i, j = tf.meshgrid(tf.range(rows), tf.range(cols), indexing='ij')
blue_channel = tf.cast((i + j) % 2 == 0, dtype=tf.float32)

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


kernels = tf.constant([
    # 水平边缘检测核 - 只对红色通道(通道0)有响应
    [[[-1, 1], [0, 0]],  # 红色通道
     [[0, 0], [0, 0]],   # 绿色通道 - 全部为0
     [[0, 0], [0, 0]]],  # 蓝色通道 - 全部为0
    
], dtype=tf.float32)

# 调整形状为 (输出通道数, 输入通道数, 高度, 宽度)
kernels = tf.transpose(kernels, [2, 3, 1, 0])
print("\n卷积核形状:", kernels.shape)

# 应用多通道卷积
# [filter_height, filter_width, in_channels, out_channels]
output = tf.nn.conv2d(rgb_image, kernels, strides=1, padding='VALID')
print("输出形状:", output.shape)  # (批次, 高度, 宽度, 输出通道数)

# 显示每个输出通道的结果
print("\n水平边缘检测结果 (通道0):")
print(output[0, :, :, 0].numpy())
