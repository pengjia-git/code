import tensorflow as tf

def conv(X,K):
    h,w=K.shape
    Xh,Xw=X.shape
    y=tf.Variable(tf.zeros((Xh-h+1,Xw-w+1),dtype=tf.float32))
    # print(f"w={w},h={h},y={y.shape}")
    for i in range(y.shape[0]):
        for j in range(y.shape[1]):
            y[i,j].assign(tf.reduce_sum(X[i:i+h,j:j+w]*K))
    return y

X=tf.constant([[0,1,2],[3,4,5],[6,7,8],[9,10,11]],dtype=tf.float32)
K=tf.constant([[0,1],[2,3]],dtype=tf.float32)

y=conv(X,K)
print(y)