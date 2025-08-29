#overfitting upderfitting 
import math
import tensorflow as tf
import numpy as np
from tensorflow.keras import layers, optimizers

# 设置随机种子
np.random.seed(42)
tf.random.set_seed(42)

# 数据生成 (与您原始代码相同)
max_degree = 20
n_train, n_test = 100, 100
true_w = np.zeros(max_degree)
true_w[0:4] = np.array([5, 1.2, -3.4, 5.6])

features = np.random.normal(size=(n_train + n_test, 1)).astype(np.float32)
np.random.shuffle(features)
poly_features = np.power(features, np.arange(max_degree,dtype=np.float32).reshape(1, -1))
for i in range(max_degree):
    poly_features[:, i] /= math.gamma(i + 1)
labels = np.dot(poly_features, true_w)
labels += np.random.normal(scale=0.1, size=labels.shape)

# 转换为TensorFlow张量
features = tf.constant(features, dtype=tf.float32)
poly_features = tf.constant(poly_features, dtype=tf.float32)
labels = tf.constant(labels, dtype=tf.float32)

# 数据集准备
split_index = n_train
train_features = features[:split_index]
test_features = features[split_index:]
train_labels = labels[:split_index]
test_labels = labels[split_index:]

train_dataset = tf.data.Dataset.from_tensor_slices((train_features, train_labels)).batch(10)
test_dataset = tf.data.Dataset.from_tensor_slices((test_features, test_labels)).batch(10)

# 修正的网络定义 - 使用TensorFlow运算
class PolyModel(tf.keras.Model):
    def __init__(self, degree=8):
        super(PolyModel, self).__init__()
        self.degree = degree
        # Use self.add_weight() instead of tf.Variable() to register with Keras
        self.w = self.add_weight(shape=[degree], 
                               initializer=tf.random_normal_initializer(stddev=0.1),
                               dtype=tf.float32, 
                               name='weights')
        self.b = self.add_weight(shape=[1],
                               initializer=tf.zeros_initializer(),
                               dtype=tf.float32,
                               name='bias')
        
    def call(self, X):
        # 正确使用TensorFlow生成多项式特征
        # 形状: (batch_size, 1) -> (batch_size, self.degree)
        exponents = tf.range(0, self.degree, dtype=tf.float32)
        poly = tf.map_fn(lambda x: tf.pow(x, exponents), X)
        
        # 应用与数据生成相同的归一化
        gamma_factors = [1.0 / math.gamma(i + 1) for i in range(self.degree)]
        poly = poly * tf.constant(gamma_factors, dtype=tf.float32)
        
        # 线性回归: (batch_size, degree) * (degree,) -> (batch_size,)
        return tf.tensordot(poly, self.w, axes=1) + self.b

# 创建模型和优化器
model = PolyModel(degree=6)
optimizer = optimizers.Adam(learning_rate=0.01)

# 训练循环
for epoch in range(2000):
    for batch_x, batch_y in train_dataset:
        with tf.GradientTape() as tape:
            pred = model(batch_x)
            # 确保形状匹配: (batch_size,) 和 (batch_size,)
            loss = tf.reduce_mean(tf.square(pred - batch_y))
            
        # 计算和应用梯度
        gradients = tape.gradient(loss, model.trainable_variables)
        optimizer.apply_gradients(zip(gradients, model.trainable_variables))
        
    print(f"Epoch {epoch}, Loss: {loss.numpy()}, Weights: {model.w.numpy()}")
    
    # 可选: 每100个epoch检查测试损失
    if epoch % 100 == 0:
        test_pred = model(test_features)
        test_loss = tf.reduce_mean(tf.square(test_pred - test_labels))
        print(f"Test Loss at Epoch {epoch}: {test_loss.numpy()}")