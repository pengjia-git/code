
import numpy as np

# 创建一个布尔数组
bool_array = np.array([True, False, True])

a = np.array([3,4,5])  
a[bool_array]=8
print(a)