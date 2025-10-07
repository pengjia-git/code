import tensorflow as tf
from d2l import tensorflow as d2l

X, W_xh = tf.random.normal((3, 1), 0, 1), tf.random.normal((1, 4), 0, 1)
H, W_hh = tf.random.normal((3, 4), 0, 1), tf.random.normal((4, 4), 0, 1)
tf.matmul(X, W_xh) + tf.matmul(H, W_hh)
print(X)
print(H)
ex=tf.concat((X, H), 1)
print(ex)