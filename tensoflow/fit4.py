import random
import math
import numpy as np
import tensorflow as tf
from tensorflow.keras import layers, optimizers

tf.random.set_seed(46)

num=100
max_degree=20
X=tf.random.normal(shape=(num,1),dtype=tf.float32)
X=tf.pow(X,range(max_degree))
# Use TensorFlow operations instead of item assignment
gamma_factors = tf.constant([math.gamma(i+1) for i in range(max_degree)], dtype=tf.float32)
X = X / gamma_factors
#产生随机数x，根据线性模型，y=w1+w2*x+w3*x^2 得到对应的y ,然后对y 添加噪声
#这样就产生了真实的数据集。我们实验的目标就是通过这个数据集，来学习到w和b
def synsetic_pow_data(w,num):
    sub_X=X[:,0:len(w)]
    Y=tf.matmul(sub_X,tf.reshape(w,(-1,1)))
    #给y添加噪声
    Y+=tf.random.normal(shape=Y.shape,stddev=0.01,dtype=tf.float32)
    if(num <= 10):
        print("X----------------")
        print(sub_X)

    if(num <= 10):
        print("Y----------------")
        print(Y)
    return sub_X,tf.reshape(Y,(-1,1))

def data_iter(batch_size,features,labels):
    num=len(features)
    indices=list(range(num))
    random.shuffle(indices)
    for i in range(0,num,batch_size):
        last=min(i+batch_size,num)
        j=tf.constant(indices[i:last])
        yield tf.gather(features,j),tf.gather(labels,j)

#x是固定的feature数据，具体到某一次，w,b是固定的，算出来的就是预测值 y_hat
def net(x,w):
    return tf.matmul(x,w)

def loss(y_hat,y):
    return tf.reduce_mean((y_hat-y)**2)

def sgd(params,grads,lr,batch_size):
    for param,grad in zip(params,grads):
        param.assign_sub(lr*grad/batch_size)

def test(x):
    x[0]=3

true_w=tf.constant([1.1,-4.6,3.5])
sub_true_X,Y=synsetic_pow_data(true_w,num)

batch_size=20

#train degree
train_degree=3
w=tf.Variable(tf.random.normal(shape=(train_degree,1),stddev=0.01,mean=0),dtype=tf.float32,trainable=True)
sub_train_X=X[:,0:train_degree]
train_features,test_features=sub_train_X[:num//10*9],sub_train_X[num//10*9:]
train_labels,test_labels=Y[:num//10*9],Y[num//10*9:]
print(f"init w={w}")
print(f"init train_features={train_features}")
lr=0.01
num_epochs=1500

optimizer = optimizers.Adam(learning_rate=0.01)
for epoch in range(num_epochs):
    for x,y in data_iter(batch_size,train_features,train_labels):
        with tf.GradientTape() as tape:
            y_hat=net(x,w)
            l=loss(y_hat,y)
        grads=tape.gradient(l,[w])
        optimizer.apply_gradients(zip(grads, [w]))
    print(f"epoch={epoch} w={w.numpy()}   l={l.numpy()},test l={loss(net(test_features,w),test_labels)}")
    #l=6.864855822641402e-05,test l=0.00019156304188072681