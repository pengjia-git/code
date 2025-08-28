import tensorflow as tf
from tensorflow.keras.datasets import fashion_mnist
import os

# 1. 数据准备
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()
train_images = train_images / 255.0  # 归一化
test_images = test_images / 255.0
# 打印train_images的数据类型
#print(train_images.dtype)


# 展平图像并确保数据类型一致
train_images = train_images.reshape((-1, 28*28)).astype('float32')
test_images = test_images.reshape((-1, 28*28)).astype('float32')

# 确保标签为int64类型
train_labels = train_labels.astype('int64')
test_labels = test_labels.astype('int64')

# 2. 模型参数
# 隐藏层1参数
W1 = tf.Variable(tf.random.normal([784, 1024], stddev=0.1))
b1 = tf.Variable(tf.zeros([1024]))

# 隐藏层2参数
W2 = tf.Variable(tf.random.normal([1024, 256], stddev=0.1))
b2 = tf.Variable(tf.zeros([256]))

# 输出层参数
W3 = tf.Variable(tf.random.normal([256, 10], stddev=0.1, dtype=tf.float32))
b3 = tf.Variable(tf.zeros([10], dtype=tf.float32))


# 3. 模型函数
def model(x):
    # 隐藏层1
    h1 = tf.nn.relu(tf.matmul(x, W1) + b1)
    # 隐藏层2
    h2 = tf.nn.relu(tf.matmul(h1, W2) + b2)
    # 输出层
    return tf.nn.softmax(tf.matmul(h2, W3) + b3)

# 4. 训练
optimizer = tf.optimizers.SGD(0.01)

# --- 新增：设置检查点 ---
checkpoint_dir = './training_checkpoints'
checkpoint_prefix = os.path.join(checkpoint_dir, "ckpt")

# 创建一个Checkpoint，指定需要保存的对象
ckpt = tf.train.Checkpoint(optimizer=optimizer,
                           W1=W1, b1=b1,
                           W2=W2, b2=b2,
                           W3=W3, b3=b3)

# 创建一个CheckpointManager来管理所有检查点
manager = tf.train.CheckpointManager(ckpt, checkpoint_dir, max_to_keep=3)

# 尝试恢复最新的检查点
ckpt.restore(manager.latest_checkpoint)
if manager.latest_checkpoint:
    print(f"Restored from {manager.latest_checkpoint}")
else:
    print("Initializing from scratch.")
# --- 检查点设置结束 ---


# 创建数据集用于批处理
train_dataset = tf.data.Dataset.from_tensor_slices((train_images, train_labels)).batch(32)
test_dataset = tf.data.Dataset.from_tensor_slices((test_images, test_labels)).batch(32)

for epoch in range(20):
    # 训练阶段
    for batch_x, batch_y in train_dataset:
        with tf.GradientTape() as tape:
            pred = model(batch_x)
            # 使用数值稳定的交叉熵损失
            loss = tf.reduce_mean(tf.keras.losses.sparse_categorical_crossentropy(batch_y, pred))
        
        trainable_vars = [W1, b1, W2, b2, W3, b3]
        gradients = tape.gradient(loss, trainable_vars)
        optimizer.apply_gradients(zip(gradients, trainable_vars))
    
    # 评估阶段
    correct_predictions = 0
    total_samples = 0
    for batch_x, batch_y in test_dataset:
        test_pred = tf.argmax(model(batch_x), axis=1)
        correct_predictions += tf.reduce_sum(tf.cast(tf.equal(test_pred, batch_y), tf.float32))
        total_samples += batch_x.shape[0]
    
    accuracy = correct_predictions / total_samples
    print(f"Epoch {epoch}, Test Accuracy: {accuracy.numpy()}")

    # --- 新增：保存检查点 ---
    save_path = manager.save()
    print(f"Saved checkpoint for epoch {epoch}: {save_path}")
    # --- 保存结束 ---

    #final accuracy Epoch 9, Test Accuracy: 0.8555999994277954
    # 修改输出模型参数为随机值，重新训练后结果是 0.8618999719619751
    # 修改学习率呢？0.84 反而下降
    # 增加学习循环次数 0.8675
    # 增加hide层的宽度呢？--当前只有一层隐藏层  0.874  训练时间 5m17.413s
    # 增加一层深度呢  训练时间 6m33.195s 准确率0.8798999786376953
    # 在此基础上 将第一层深度改为1024，第二层深度改为256