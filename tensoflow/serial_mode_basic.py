import tensorflow as tf
import matplotlib.pyplot as plt

#将耦合进的误差减小，用800个点训练出的模型误差很大，增加数据量后，误差明显减小。
#再次证明，数据对于当前深度学习范式，很重要。
T = 2000  # 总共产生1000个点
time = tf.range(1, T + 1, dtype=tf.float32)
x = tf.sin(0.01 * time) + tf.random.normal([T], 0, 0.02)

# 将TensorFlow张量转换为numpy数组以便绘图
time_np = time.numpy()
x_np = x.numpy()

tau = 4
features = tf.Variable(tf.zeros((T - tau, tau)))
for i in range(tau):
    features[:, i].assign(x[i: T - tau + i])
labels = tf.reshape(x[tau:], (-1, 1))

batch_size=32
train_size=1800

train_dataset=tf.data.Dataset.from_tensor_slices((features[:train_size],labels[:train_size])).batch(batch_size)


# 一个简单的多层感知机
def get_net():
    net = tf.keras.Sequential([tf.keras.layers.Dense(10, activation='relu'),
                              tf.keras.layers.Dense(1)])
    return net

# 最小均方损失。注意：MeanSquaredError计算平方误差时不带系数1/2
loss = tf.keras.losses.MeanSquaredError()

optimizer = tf.optimizers.Adam(0.001)

model = get_net()
model.build(input_shape=(None, tau))
print(model.summary())


for epoch in range(10):
    # 训练阶段
    for batch_x, batch_y in train_dataset:
        with tf.GradientTape() as tape:
            pred = model(batch_x)
            lossval = loss(batch_y, pred) 
        gradients = tape.gradient(lossval, model.trainable_variables)  # 修改这里
        optimizer.apply_gradients(zip(gradients, model.trainable_variables))  # 修改这里
   
    print(f"Epoch {epoch}, Loss: {lossval.numpy()}")

multistep_preds = tf.Variable(tf.zeros(T))
multistep_preds[: tau].assign(x[: tau])
for i in range(100):
    pred=model(tf.reshape(multistep_preds[i:i+tau],(1,-1)))
    # 将预测值赋给multistep_preds的第i+tau个元素
    multistep_preds[i+tau].assign(tf.squeeze(pred))

# 创建图形
plt.figure(figsize=(12, 6))
plt.plot(time_np, x_np,'b')
pred=  model(features)
plt.plot(time_np[tau:], pred.numpy(),'g')

# print(f"multistep_preds.shape {multistep_preds.shape}")
plt.plot(time_np, multistep_preds.numpy(),'r')
plt.xlabel('time')
plt.ylabel('value')
plt.title('sin wave with noise')
plt.grid(True)
plt.show()