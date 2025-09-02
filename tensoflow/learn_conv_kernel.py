# 训练出一个卷积核，用于检测图像中的边缘
import numpy as np
import tensorflow as tf

# 1. 创建输入数据（根据图片描述）
X = tf.Variable(tf.ones((6, 8))*2)
X[:, 2:6].assign(tf.zeros(X[:, 2:6].shape))

print("输入图像:")
print(X.numpy())

# 添加通道维度 (批次大小, 高度, 宽度, 通道数)
X = tf.reshape(X, (1, 6, 8, 1))  # 批次大小为1，只有一个样本

# 2. 使用真实卷积核计算期望输出
kernel_real = tf.constant([[-1, 1]], dtype=tf.float32)
kernel_real = tf.reshape(kernel_real, (1, 2, 1, 1))  # (高度, 宽度, 输入通道, 输出通道)

# 计算期望输出
Y_true = tf.nn.conv2d(X, kernel_real, strides=1, padding='VALID')
print("\n期望输出形状:", Y_true.shape)
print("期望输出:")
print(Y_true.numpy().reshape(Y_true.shape[1], Y_true.shape[2]))

# 3. 初始化可训练的卷积核（接近0的随机值）
kernel = tf.Variable(tf.random.normal([1, 2, 1, 1], mean=0.0, stddev=0.1))

# 4. 定义训练参数
learning_rate = 0.01
epochs = 1000

# 5. 训练循环
for epoch in range(epochs):
    with tf.GradientTape() as tape:
        # 前向传播
        Y_pred = tf.nn.conv2d(X, kernel, strides=1, padding='VALID')
        
        # 计算损失（均方误差）
        loss = tf.reduce_mean(tf.square(Y_pred - Y_true))
    
    # 计算梯度
    gradients = tape.gradient(loss, [kernel])
    
    # 更新参数（手动实现梯度下降）
    kernel.assign_sub(learning_rate * gradients[0])
    
    # 每10轮打印一次进度
    if epoch % 10 == 0:
        print(f"Epoch {epoch}, Loss: {loss.numpy()}, Kernel: {kernel.numpy().flatten()}")

# 6. 输出最终结果
print(f"\n最终学习到的卷积核: {kernel.numpy().flatten()}")
print(f"真实卷积核: [-1, 1]")

# 7. 验证效果
Y_pred_final = tf.nn.conv2d(X, kernel, strides=1, padding='VALID')
print("\n预测结果:")
print(Y_pred_final.numpy().reshape(Y_pred_final.shape[1], Y_pred_final.shape[2]))
print("\n期望结果:")
print(Y_true.numpy().reshape(Y_true.shape[1], Y_true.shape[2]))