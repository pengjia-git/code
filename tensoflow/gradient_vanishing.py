
import numpy as np
import tensorflow as tf

x=tf.Variable(tf.range(-8,8,0.1))

with tf.GradientTape() as tape:
    y=tf.nn.sigmoid(x)

# 计算 y 对 x 的导数
dy_dx = tape.gradient(y, x)

# 打印结果
print("x =", x.numpy())
print("y = sigmoid(x) =", y.numpy())
print("dy/dx =", dy_dx.numpy())