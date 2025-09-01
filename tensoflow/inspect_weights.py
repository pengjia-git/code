import h5py
import numpy as np

# 设置 NumPy 打印选项，使其更容易阅读
np.set_printoptions(precision=4, suppress=True)

def print_h5_structure(name, obj):
    """
    一个回调函数，用于递归地打印 HDF5 文件的结构。
    """
    # 'name' 是组或数据集的完整路径
    # 'obj' 是 h5py 的 Group 或 Dataset 对象
    indent = '  ' * name.count('/')
    if isinstance(obj, h5py.Group):
        # 如果是组（Group），只打印组名
        print(f"{indent}Group: {name}")
    elif isinstance(obj, h5py.Dataset):
        # 如果是数据集（Dataset），打印名称、形状和数据
        print(f"{indent}Dataset: {name}")
        print(f"{indent}  Shape: {obj.shape}")
        print(f"{indent}  Dtype: {obj.dtype}")
        print(f"{indent}  Value (first 5 elements):")
        
        # --- 修正部分 ---
        # 直接使用 [:] 读取数据集到 numpy 数组
        data = obj[:]
        print(f"{indent}  {data.flatten()[:5]}...")
        # --- 修正结束 ---


# 替换为您的权重文件路径
file_path = 'my.params.weights.h5'

try:
    with h5py.File(file_path, 'r') as f:
        print(f"Inspecting contents of: {file_path}\n")
        # f.visititems 会遍历文件中的所有项目并应用回调函数
        f.visititems(print_h5_structure)
except FileNotFoundError:
    print(f"Error: File not found at {file_path}")
except Exception as e:
    print(f"An error occurred: {e}")