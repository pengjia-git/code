#overfitting upderfitting 
import math
import tensorflow as tf
import numpy as np

# 在代码开头添加
np.random.seed(42)
tf.random.set_seed(42)

max_degree = 20  # 多项式的最大阶数
n_train, n_test = 1000, 1000  # 训练和测试数据集大小
true_w = np.zeros(max_degree)  # 分配大量的空间
true_w[0:4] = np.array([5, 1.2, -3.4, 5.6])

features = np.random.normal(size=(n_train + n_test, 1)).astype(np.float32)
np.random.shuffle(features)
poly_features = np.power(features, np.arange(max_degree,dtype=np.float32).reshape(1, -1))
for i in range(max_degree):
    poly_features[:, i] /= math.gamma(i + 1)  # gamma(n)=(n-1)!
# labels的维度:(n_train+n_test,)
labels = np.dot(poly_features, true_w)
labels += np.random.normal(scale=0.1, size=labels.shape)

# NumPy ndarray转换为tensor
true_w, features, poly_features, labels = [tf.constant(x, dtype=
    tf.float32) for x in [true_w, features, poly_features, labels]]


#用二阶拟合
w = tf.Variable(tf.random.normal([3], stddev=0.1),dtype=tf.float32)
b = tf.Variable(tf.zeros([1]),dtype=tf.float32)

def net(X):
    poly= np.power(X,[1,2,3],dtype=np.float32)
    # print("poly.shape:",poly.shape)
    # print(tf.matmul(poly,w).shape)
    return tf.matmul(poly,tf.reshape(w,[-1,1]))+b
    
# loss=tf.reduce_mean(tf.square(net-labels))

optimizer = tf.optimizers.Adam(learning_rate=0.01)

# 获取样本总数
num_samples = features.shape[0]
# 计算分割点
split_index = num_samples // 2

# 将 features 和 labels 分割成训练集和测试集
train_features = features[:split_index]
test_features = features[split_index:]
train_labels = labels[:split_index]
test_labels = labels[split_index:]

# 为训练集和测试集创建 Dataset
train_dataset = tf.data.Dataset.from_tensor_slices((train_features, train_labels)).batch(50)
test_dataset = tf.data.Dataset.from_tensor_slices((test_features, test_labels)).batch(50)

patience=10
wait=0
best_loss=float('inf')


for epoch in range(2000):
    # 训练阶段
    for batch_x, batch_y in train_dataset:
        with tf.GradientTape() as tape:
            pred = net(batch_x)
            loss=tf.reduce_mean(tf.square(pred-batch_y))
        trainable_vars = [w,b]
        gradients = tape.gradient(loss, trainable_vars)
        optimizer.apply_gradients(zip(gradients, trainable_vars))
    print("epoch:",epoch,"loss:",loss)
    #二阶 loss 3.89  7.04  --不是很稳定 不知道是不是跟学习率有关，还是数据量大小了