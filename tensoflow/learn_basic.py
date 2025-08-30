import random
import numpy as np
import tensorflow as tf
tf.random.set_seed(40)

#产生随机数x，根据线性模型，y=wx+b 得到对应的y ,然后对y 添加噪声
#这样就产生了真实的数据集。我们实验的目标就是通过这个数据集，来学习到w和b
def synsetic_data(w,b,num):
    # 随机数是什么形状？ num x len(w) -->  比如 w是3个元素 ，表达式就相当于 y=w1x1+w2x2+w3x3+b
    X=tf.random.normal(shape=(num,len(w)),dtype=tf.float32)
    Y=tf.matmul(X,tf.reshape(w,(-1,1)))+b  #num x w ,w x1 --> num x 1
    #给y添加噪声
    Y+=tf.random.normal(shape=Y.shape,stddev=0.01,dtype=tf.float32)
    if(num <= 10):
        print(Y)
    return X,tf.reshape(Y,(-1,1))

def data_iter(batch_size,features,labels):
    num=len(features)
    indices=list(range(num))
    random.shuffle(indices)
    for i in range(0,num,batch_size):
        last=min(i+batch_size,num)
        j=tf.constant(indices[i:last])
        yield tf.gather(features,j),tf.gather(labels,j)

#x是固定的feature数据，具体到某一次，w,b是固定的，算出来的就是预测值 y_hat
def net(x,w,b):
    return tf.matmul(x,w)+b

def loss(y_hat,y):
    return tf.reduce_mean((y_hat-y)**2)

def sgd(params,grads,lr,batch_size):
    for param,grad in zip(params,grads):
        param.assign_sub(lr*grad/batch_size)

def test(x):
    x[0]=3

true_w=tf.constant([1.1,-4.6,3.5])
true_b=4.2
num=1000
X,Y=synsetic_data(true_w,true_b,num)
train_features,test_features=X[:num//2],X[num//2:]
train_labels,test_labels=Y[:num//2],Y[num//2:]


if(num <= 10):
    print("---------")
    print(Y)

batch_size=20

w=tf.Variable(tf.random.normal(shape=tf.reshape(true_w,(-1,1)).shape ,stddev=0.01,mean=0),dtype=tf.float32,trainable=True)
b=tf.Variable(tf.zeros(1),dtype=tf.float32,trainable=True)
print(f"init w={w}  b={b}")

lr=0.01
num_epochs=200

for epoch in range(num_epochs):
    for x,y in data_iter(batch_size,train_features,train_labels):
        with tf.GradientTape() as tape:
            y_hat=net(x,w,b)
            l=loss(y_hat,y)
        grads=tape.gradient(l,[w,b])
        sgd([w,b],grads,lr,batch_size)
    print(f"epoch={epoch} w={w.numpy()}  b={b.numpy()} l={l.numpy()},test l={loss(net(test_features,w,b),test_labels)}")
