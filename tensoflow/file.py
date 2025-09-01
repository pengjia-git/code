import numpy as np
import tensorflow as tf

x = tf.range(4)
np.save('x-file.npy', x)

x2=np.load('x-file.npy',allow_pickle=True)
print(x2)