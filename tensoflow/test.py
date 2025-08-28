
import math
import tensorflow as tf
import numpy as np


x = tf.constant([[ 3],[4]])  # shape (1, 3)
y = tf.constant([[2, 3]])    # shape (2, 1)
result = tf.pow(x, y)
print(result)