import tensorflow as tf
from d2l import tensorflow as d2l
import random

def noline(x,y):
    return x**2-3+y

net=noline
for i in range(10):
    # Convert i to a TensorFlow tensor with gradient tracking enabled
    x = tf.Variable(float(i),trainable=True)
    y = tf.Variable(float(i),trainable=True)
    with tf.GradientTape() as g:
        l=net(x,y)
    dx,dy=g.gradient(l, [x,y])
    print(dx.numpy(),dy.numpy())