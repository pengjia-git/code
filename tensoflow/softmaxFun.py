import tensorflow as tf

# 示例1：一维张量
logits = tf.constant([2.0, 1.0, 0.1])
probabilities = tf.nn.softmax(logits)
print("一维 softmax:", probabilities.numpy())

# 示例2：二维张量（批量数据）
batch_logits = tf.constant([[1.0, 2.0, 3.0],
                           [1.0, 2.0, 1.0]])
batch_probs = tf.nn.softmax(batch_logits, axis=1)
print("二维 softmax:\n", batch_probs.numpy())