
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
def create_net():
    return tf.keras.models.Sequential([
        myBlock(),
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dense(4, activation=tf.nn.relu),
        tf.keras.layers.Dense(1),
    ])

net=create_net()
x=tf.Variable(tf.constant([[1,2,3,4],[4,5,6,7]],dtype=tf.float32),dtype=tf.float32)
y=net(x)
print(y)

net.save_weights("my.params.weights.h5")
clone=create_net()
clone(x)  # 在加载权重前，需要先构建模型
clone.load_weights("my.params.weights.h5")
y_clone=clone(x)
print(y_clone)
