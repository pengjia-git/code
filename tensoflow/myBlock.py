
import tensorflow as tf
from tensorflow.keras import layers, optimizers

class myBlock(tf.keras.Model):
    def __init__(self):
        super().__init__()
        
        
    def call(self,x):
        self.w=tf.Variable(tf.random.normal(shape=(x.shape[1],1),dtype=tf.float32))
        return tf.matmul(x,self.w)

net=myBlock()
x=tf.Variable(tf.constant([[1,2,3],[4,5,6]],dtype=tf.float32),dtype=tf.float32)
print(net(x))