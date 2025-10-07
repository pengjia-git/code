import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf

def show_heatmaps(matrices, xlabel, ylabel, titles=None, figsize=(2.5, 2.5), cmap='Reds'):
    """显示矩阵热图"""
    # 确保 matrices 是 4D 张量 (num_rows, num_cols, height, width)
    if len(matrices.shape) == 2:
        matrices = matrices[np.newaxis, np.newaxis, :, :]
    elif len(matrices.shape) == 3:
        matrices = matrices[np.newaxis, :, :, :]
    
    num_rows, num_cols = matrices.shape[0], matrices.shape[1]
    
    # 创建子图
    fig, axes = plt.subplots(num_rows, num_cols, figsize=figsize,
                            sharex=True, sharey=True, squeeze=False)
    
    # 用于颜色条的统一标度
    pcm = None
    
    for i in range(num_rows):
        for j in range(num_cols):
            ax = axes[i, j]
            matrix = matrices[i, j]
            
            # 转换为 numpy 数组并显示热力图
            if hasattr(matrix, 'numpy'):
                matrix_data = matrix.numpy()
            else:
                matrix_data = matrix
            print(f"matrix_data={matrix_data}") 
            matrix_data[0,0] = 0.2
            pcm = ax.imshow(matrix_data, cmap=cmap, vmin=0, vmax=1)
            
            # 设置标签
            if i == num_rows - 1:
                ax.set_xlabel(xlabel)
            if j == 0:
                ax.set_ylabel(ylabel)
            if titles:
                ax.set_title(titles[j] if j < len(titles) else '')
            
            # 设置刻度
            ax.set_xticks([0, matrix_data.shape[1]-1])
            ax.set_yticks([0, matrix_data.shape[0]-1])
    
    # 添加颜色条
    # if pcm is not None:
    #     fig.colorbar(pcm, ax=axes, shrink=0.6)
    
    plt.tight_layout()
    plt.show()

# 测试代码 - 创建一个类似于您描述的对角线注意力权重矩阵
def create_diagonal_attention(seq_len=9):
    """创建对角线注意力权重矩阵"""
    # 创建一个接近单位矩阵的矩阵来模拟对角线注意力
    attention_weights = np.eye(seq_len) * 0.8
    # print(attention_weights)
    
    # 添加一些随机噪声使图像更真实
    np.random.seed(42)  # 固定随机种子以便结果可重现
    noise = np.random.normal(0, 0.1, (seq_len, seq_len))
    # print(attention_weights + noise)
    # exit()
    attention_weights = np.clip(attention_weights + noise, 0, 1)
    
    # 强化对角线模式
    # for i in range(seq_len):
    #     for j in range(seq_len):
    #         if i == j:
    #             attention_weights[i, j] = 0.9 + 0.1 * np.random.random()
    #         else:
    #             # 离对角线越远，权重越小
    #             distance = abs(i - j)
    #             attention_weights[i, j] = max(0, attention_weights[i, j] - distance * 0.1)
    
    return tf.constant(attention_weights, dtype=tf.float32)

# 生成并显示热力图
attention_weights = create_diagonal_attention(9)
# print(attention_weights)
# exit()
attention_weights = tf.reshape(attention_weights, (1, 1, 9, 9))
# print(f"shapes: {attention_weights.shape},shapes[0]={attention_weights.shape[0]},shapes[1]={attention_weights.shape[1]}")
# exit()
show_heatmaps(attention_weights, xlabel='Keys', ylabel='Queries')