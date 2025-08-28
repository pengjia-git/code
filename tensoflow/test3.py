import tensorflow as tf

# zip 的作用演示
print("=== zip函数作用演示 ===")
# 假设有以下变量和梯度
W = tf.Variable([[1.0, 2.0], [3.0, 4.0]], name="W")  # 形状(2, 2)
b = tf.Variable([0.5, 0.5], name="b")                  # 形状(2,)

print("初始参数:")
print("W =", W.numpy())
print("b =", b.numpy())

gradients = [
    tf.constant([[0.1, 0.2], [0.3, 0.4]]),  # W的梯度
    tf.constant([0.05, 0.05])               # b的梯度
]

print("\n梯度:")
print("grad_W =", gradients[0].numpy())
print("grad_b =", gradients[1].numpy())

# 不使用zip的情况 - 这样传递给optimizer是不正确的
print("\n直接传递两个列表给optimizer是不正确的:")
print("gradients =", gradients)
print("variables = [W, b] =", [W, b])
print("optimizer无法知道哪个梯度对应哪个变量")

# 使用zip配对 - 正确的方式
print("\n使用zip配对后:")
zipped = list(zip(gradients, [W, b]))
print("zip(gradients, [W, b]) =")
for i, (grad, var) in enumerate(zipped):
    print(f"  ({i}): 梯度{grad.numpy()} 用于更新 变量{var.name}")

# 模拟optimizer.apply_gradients的工作方式
print("\n模拟optimizer.apply_gradients(zip(gradients, [W, b]))的更新过程:")
learning_rate = 0.1
for grad, var in zipped:
    print(f"更新 {var.name}: {var.numpy()} - {learning_rate} * {grad.numpy()}")
    var.assign_sub(learning_rate * grad)  # 梯度下降更新

print("\n更新后的参数:")
print("W =", W.numpy())
print("b =", b.numpy())

print("\n结论:")
print("zip函数将梯度和对应的变量配对，确保优化器知道每个变量应该使用哪个梯度进行更新。")