import tensorflow as tf
from tensorflow.keras import datasets, layers, models
# import matplotlib.pyplot as plt

# 1. 加载和预处理数据 (基于你之前的代码)
# 加载 CIFAR-10 数据集
(x_train, y_train), (x_test, y_test) = datasets.cifar10.load_data()

# 将标签展平为一维数组 (用于 sparse_categorical_crossentropy 损失函数)
y_train = y_train.flatten()
y_test = y_test.flatten()

# 定义预处理函数
def preprocess_images(images, labels, training=True):
    """
    预处理图像数据，适配 AlexNet 及 CIFAR-10 特点
    """
    # 转换数据类型并归一化到 [0, 1] 范围
    images = tf.cast(images, tf.float32) / 255.0
    
    # 调整图像尺寸: 原始 AlexNet 输入为 224x224，但 CIFAR-10 为 32x32
    # 这里放大到 64x64 作为折衷
    target_size = 64
    images = tf.image.resize(images, [target_size, target_size])
    
    # 数据增强 (仅在训练模式下使用)
    if training:
        # 随机水平翻转
        images = tf.image.random_flip_left_right(images)
        # 随机调整亮度、对比度
        images = tf.image.random_brightness(images, max_delta=0.2)
        images = tf.image.random_contrast(images, lower=0.8, upper=1.2)
        # 随机裁剪
        images = tf.image.resize_with_crop_or_pad(images, target_size+8, target_size+8)
        images = tf.image.random_crop(images, size=[tf.shape(images)[0], target_size, target_size, 3])
    
    # 标准化：使用 ImageNet 的均值和方差
    # 注意：这里使用 AlexNet 的预处理方式，尽管 CIFAR-10 是不同的数据集
    images = tf.keras.applications.alexnet.preprocess_input(images)
    
    return images, labels

# 创建 TensorFlow Dataset 对象并应用预处理
batch_size = 128

# 训练集 Dataset
train_dataset = tf.data.Dataset.from_tensor_slices((x_train, y_train))
train_dataset = train_dataset.shuffle(buffer_size=10000)
train_dataset = train_dataset.map(lambda x, y: preprocess_images(x, y, training=True),
                                  num_parallel_calls=tf.data.AUTOTUNE)
train_dataset = train_dataset.batch(batch_size)
train_dataset = train_dataset.prefetch(buffer_size=tf.data.AUTOTUNE)

# 测试集 Dataset (不需要数据增强)
test_dataset = tf.data.Dataset.from_tensor_slices((x_test, y_test))
test_dataset = test_dataset.map(lambda x, y: preprocess_images(x, y, training=False),
                                num_parallel_calls=tf.data.AUTOTUNE)
test_dataset = test_dataset.batch(batch_size)
test_dataset = test_dataset.prefetch(buffer_size=tf.data.AUTOTUNE)

# 2. 定义 AlexNet 模型
def create_alexnet(input_shape=(64, 64, 3), num_classes=10):
    """
    创建 AlexNet 模型
    参数:
    input_shape: 输入图像的形状 (高度, 宽度, 通道数)
    num_classes: 分类类别数
    """
    model = models.Sequential([
        # 第一卷积层 [1,5](@ref)
        layers.Conv2D(96, (11, 11), strides=4, activation='relu', input_shape=input_shape),
        layers.BatchNormalization(),  # 添加批归一化，有助于训练稳定性
        layers.MaxPooling2D(pool_size=3, strides=2),
        
        # 第二卷积层 [1,5](@ref)
        layers.Conv2D(256, (5, 5), padding='same', activation='relu'),
        layers.BatchNormalization(),
        layers.MaxPooling2D(pool_size=3, strides=2),
        
        # 第三卷积层 [1,5](@ref)
        layers.Conv2D(384, (3, 3), padding='same', activation='relu'),
        
        # 第四卷积层 [1,5](@ref)
        layers.Conv2D(384, (3, 3), padding='same', activation='relu'),
        
        # 第五卷积层 [1,5](@ref)
        layers.Conv2D(256, (3, 3), padding='same', activation='relu'),
        layers.MaxPooling2D(pool_size=3, strides=2),
        
        # 展平层
        layers.Flatten(),
        
        # 全连接层 [1,5](@ref)
        layers.Dense(4096, activation='relu'),
        layers.Dropout(0.5),  # Dropout 防止过拟合
        
        # 全连接层
        layers.Dense(4096, activation='relu'),
        layers.Dropout(0.5),
        
        # 输出层
        layers.Dense(num_classes, activation='softmax')
    ])
    
    return model

# 创建模型
model = create_alexnet(input_shape=(64, 64, 3), num_classes=10)

# 打印模型摘要
model.summary()

# 3. 编译模型 [1,6](@ref)
model.compile(
    optimizer='adam',  # 也可以使用 SGD with momentum，如 tf.keras.optimizers.SGD(learning_rate=0.01, momentum=0.9)
    loss='sparse_categorical_crossentropy',  # 适用于整数标签
    metrics=['accuracy']
)

# 4. 训练模型 [1,6](@ref)
epochs = 20
history = model.fit(
    train_dataset,
    epochs=epochs,
    validation_data=test_dataset,
    verbose=1  # 显示训练进度
)

# 5. 评估模型 [1,6](@ref)
test_loss, test_acc = model.evaluate(test_dataset, verbose=1)
print(f'测试准确率: {test_acc * 100:.2f}%')


# 7. 保存模型 [1,6](@ref)
model.save('alexnet_cifar10.h5')
print("模型已保存为 alexnet_cifar10.h5")

# 8. 进行预测示例
# 从测试集中取出一批数据
for test_images, test_labels in test_dataset.take(1):
    # 预测前5个图像
    predictions = model.predict(test_images[:5])
    predicted_classes = tf.argmax(predictions, axis=1)
    
    print("\n预测示例:")
    for i in range(5):
        print(f"真实标签: {test_labels[i]}, 预测标签: {predicted_classes[i]}, 置信度: {tf.reduce_max(predictions[i]):.2f}")