import matplotlib.pyplot as plt
import numpy as np

# 创建2x2的子图网格
fig, axes = plt.subplots(2, 2, figsize=(6, 6), sharex=True, sharey=True, squeeze=False)

# 在每个子图上绘制不同的内容
x = np.linspace(0, 10, 100)

axes[0, 0].plot(x, np.sin(x))
axes[0, 0].set_title('正弦函数')

axes[0, 1].plot(x, np.cos(x))
axes[0, 1].set_title('余弦函数')

axes[1, 0].plot(x, np.tan(x))
axes[1, 0].set_title('正切函数')

axes[1, 1].plot(x, np.exp(x))
axes[1, 1].set_title('指数函数')

plt.tight_layout()
plt.show()