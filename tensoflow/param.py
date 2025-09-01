
import tensorflow as tf

class myBlock(tf.keras.Model):
    def __init__(self):
        super().__init__()
        
    def build(self, input_shape):
        self.w = self.add_weight(
            shape=(input_shape[-1], 1),
            initializer="random_normal",
            trainable=True,
        )
        
    def call(self,x):
        return tf.matmul(x,self.w)

net = tf.keras.models.Sequential([
    myBlock(),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(4, activation=tf.nn.relu),
    tf.keras.layers.Dense(1),
])

x=tf.Variable(tf.constant([[1,2,3,4],[4,5,6,7]],dtype=tf.float32),dtype=tf.float32)
y=net(x)
print(net.layers[1].weights)