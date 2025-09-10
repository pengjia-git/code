import tensorflow as tf
from tensorflow.keras.datasets import fashion_mnist
import os

from PIL import Image
import numpy as np

# 1. 数据准备
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()

# 更高效的TensorFlow实现
def resize_with_tf(images, target_size=(224, 224)):
    # 确保输入是4D张量 (batch, height, width, channels)
    if len(images.shape) == 3:
        images = tf.expand_dims(images, axis=-1)  # 添加通道维度
    
    # 转换为3通道
    if images.shape[-1] == 1:
        images_3ch = tf.repeat(images, 3, axis=-1)
    else:
        images_3ch = images
    
    # 正确的resize操作
    resized = tf.image.resize(images_3ch, target_size, method='bilinear')
    return resized.numpy()

# 应用resize
#train_images = resize_with_tf(test_images, (224, 224))
test_images = resize_with_tf(test_images, (224, 224))
# 4. 验证形状
print(f"Resized train images shape: {test_images.shape}, data type:{test_images.dtype}")  # 应该是 (60000, 224, 224, 3)

# 选择第一张图片
sample_image = test_images[0]


# 转换为PIL图像格式
# 由于是3通道图像，直接转换为RGB
# Fashion MNIST原始数据范围是0-255，resize后可能变成浮点数
# 需要确保在保存前转换为正确的数据类型
if sample_image.dtype != np.uint8:
    # 如果数据在0-1范围，转换回0-255
    if sample_image.max() <= 1.0:
        sample_image = (sample_image * 255).astype(np.uint8)
    else:
        sample_image = sample_image.astype(np.uint8)

# 6. 转换为PIL图像格式并保存
pil_image = Image.fromarray(sample_image, 'RGB')

# 保存为BMP格式
bmp_path = '/root/code/tensoflow/fashion_sample.bmp'
pil_image.save(bmp_path, 'BMP')

print(f"图片已保存到: {bmp_path}")
print(f"图片形状: {sample_image.shape}")
print(f"图片数据类型: {sample_image.dtype}")

train_images = train_images / 255.0  # 归一化
test_images = test_images / 255.0
# 打印train_images的数据类型
print(train_images.dtype)



# 确保标签为int64类型
train_labels = train_labels.astype('int64')
test_labels = test_labels.astype('int64')

def net():
    return tf.keras.models.Sequential([
        # 这里使用一个11*11的更大窗口来捕捉对象。
        # 同时，步幅为4，以减少输出的高度和宽度。
        # 另外，输出通道的数目远大于LeNet
        tf.keras.layers.Conv2D(filters=96, kernel_size=11, strides=4,
                               activation='relu'),
        tf.keras.layers.MaxPool2D(pool_size=3, strides=2),
        # 减小卷积窗口，使用填充为2来使得输入与输出的高和宽一致，且增大输出通道数
        tf.keras.layers.Conv2D(filters=256, kernel_size=5, padding='same',
                               activation='relu'),
        tf.keras.layers.MaxPool2D(pool_size=3, strides=2),
        # 使用三个连续的卷积层和较小的卷积窗口。
        # 除了最后的卷积层，输出通道的数量进一步增加。
        # 在前两个卷积层之后，汇聚层不用于减少输入的高度和宽度
        tf.keras.layers.Conv2D(filters=384, kernel_size=3, padding='same',
                               activation='relu'),
        tf.keras.layers.Conv2D(filters=384, kernel_size=3, padding='same',
                               activation='relu'),
        tf.keras.layers.Conv2D(filters=256, kernel_size=3, padding='same',
                               activation='relu'),
        tf.keras.layers.MaxPool2D(pool_size=3, strides=2),
        tf.keras.layers.Flatten(),
        # 这里，全连接层的输出数量是LeNet中的好几倍。使用dropout层来减轻过拟合
        tf.keras.layers.Dense(4096, activation='relu'),
        tf.keras.layers.Dropout(0.5),
        tf.keras.layers.Dense(4096, activation='relu'),
        tf.keras.layers.Dropout(0.5),
        # 最后是输出层。由于这里使用Fashion-MNIST，所以用类别数为10，而非论文中的1000
        tf.keras.layers.Dense(10)
    ])

#test 
X = tf.random.uniform((1, 224, 224, 1))
for layer in net().layers:
    X = layer(X)
    print(layer.__class__.__name__, 'output shape:\t', X.shape)

# 4. 训练
optimizer = tf.optimizers.SGD(0.01)

model = net()
print(model.summary())

# 创建数据集用于批处理
train_dataset = tf.data.Dataset.from_tensor_slices((train_images, train_labels)).batch(32)
test_dataset = tf.data.Dataset.from_tensor_slices((test_images, test_labels)).batch(32)

for epoch in range(30):
    # 训练阶段
    for batch_x, batch_y in train_dataset:
        with tf.GradientTape() as tape:
            pred = model(batch_x)
            loss = tf.reduce_mean(tf.keras.losses.sparse_categorical_crossentropy(batch_y, pred, from_logits=True))
        gradients = tape.gradient(loss, model.trainable_variables)  # 修改这里
        optimizer.apply_gradients(zip(gradients, model.trainable_variables))  # 修改这里
   
    print(f"Epoch {epoch}, Loss: {loss.numpy()}")
    # 评估阶段
    correct_predictions = 0
    total_samples = 0
    for batch_x, batch_y in test_dataset:
        test_pred = tf.argmax(model(batch_x), axis=1)
        correct_predictions += tf.reduce_sum(tf.cast(tf.equal(test_pred, batch_y), tf.float32))
        total_samples += batch_x.shape[0]
    
    accuracy = correct_predictions / total_samples
    print(f"Epoch {epoch}, Test Accuracy: {accuracy.numpy()}")
    #Epoch 29, Loss: 0.2142777442932129
    #Epoch 29, Test Accuracy: 0.8798999786376953