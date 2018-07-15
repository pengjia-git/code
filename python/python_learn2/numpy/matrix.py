import numpy as np
import matplotlib.pyplot as plt

def matrix_mul_vector(matrix,vec):
	res_vec=[0,0]
	res_vec[0]=matrix[0][0]*vec[0]+matrix[0][1]*vec[1];
	res_vec[1]=matrix[1][0]*vec[0]+matrix[1][1]*vec[1];
	return res_vec

plt.figure(1)
ax = plt.subplot(111)
x = np.linspace(-2, 2, 400)  
y = x
ax.plot(x,y)


matrix_a=[[1.0,-0.3],[-0.7,0.6]]
matrix_x=[]
matrix_y=[]

for i in range(len(x)):
	vec=matrix_mul_vector(matrix_a,[x[i],y[i]])
	matrix_x.append(vec[0])
	matrix_y.append(vec[1])

ax.plot(matrix_x,matrix_y)
plt.show() 



