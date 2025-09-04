import tensorflow as tf
from tensorflow.keras.datasets import fashion_mnist
import os

# 1. 数据准备
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()
train_images = train_images / 255.0  # 归一化
test_images = test_images / 255.0
# 打印train_images的数据类型
#print(train_images.dtype)


# 修改数据形状为(样本数, 28, 28, 1)
train_images = train_images.reshape((-1, 28, 28, 1)).astype('float32')
test_images = test_images.reshape((-1, 28, 28, 1)).astype('float32')

# 确保标签为int64类型
train_labels = train_labels.astype('int64')
test_labels = test_labels.astype('int64')

def net():
    return tf.keras.models.Sequential([
        tf.keras.layers.Conv2D(filters=6, kernel_size=5, activation='sigmoid',
                               padding='same'),
        tf.keras.layers.AvgPool2D(pool_size=2, strides=2),
        tf.keras.layers.Conv2D(filters=16, kernel_size=5,
                               activation='sigmoid'),
        tf.keras.layers.AvgPool2D(pool_size=2, strides=2),
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dense(120, activation='sigmoid'),
        tf.keras.layers.Dense(84, activation='sigmoid'),
        tf.keras.layers.Dense(10)])
# 4. 训练
optimizer = tf.optimizers.SGD(0.01)

model = net()

# 创建数据集用于批处理
train_dataset = tf.data.Dataset.from_tensor_slices((train_images, train_labels)).batch(32)
test_dataset = tf.data.Dataset.from_tensor_slices((test_images, test_labels)).batch(32)

for epoch in range(20):
    # 训练阶段
    for batch_x, batch_y in train_dataset:
        with tf.GradientTape() as tape:
            pred = model(batch_x)
            loss = tf.reduce_mean(tf.keras.losses.sparse_categorical_crossentropy(batch_y, pred))
        gradients = tape.gradient(loss, model.trainable_variables)  # 修改这里
        optimizer.apply_gradients(zip(gradients, model.trainable_variables))  # 修改这里
    
    # 评估阶段
    correct_predictions = 0
    total_samples = 0
    for batch_x, batch_y in test_dataset:
        test_pred = tf.argmax(model(batch_x), axis=1)
        correct_predictions += tf.reduce_sum(tf.cast(tf.equal(test_pred, batch_y), tf.float32))
        total_samples += batch_x.shape[0]
    
    accuracy = correct_predictions / total_samples
    print(f"Epoch {epoch}, Test Accuracy: {accuracy.numpy()}")