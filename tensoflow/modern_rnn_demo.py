import tensorflow as tf
import numpy as np
import random
import collections

# 文本预处理相关函数（从text_mode1.py复制）
def read_time_machine():
    """将时间机器数据集加载到文本行的列表中"""
    with open('/Users/pengjia/work/code/tensoflow/timemachine.txt', 'r') as f:
        lines = f.readlines()
    # 跳过开头和结尾的说明文字，只保留正文内容
    return [line.strip().lower().replace('\n', ' ') for line in lines[35:3235]]

def tokenize(lines, token='word'):
    """将文本行拆分为单词或字符标记"""
    if token == 'word':
        return [line.split() for line in lines]
    elif token == 'char':
        return [list(line) for line in lines]
    else:
        print('错误：未知令牌类型：' + token)

class Vocab:
    """文本词汇表"""
    def __init__(self, tokens=None, min_freq=0, reserved_tokens=None):
        if tokens is None:
            tokens = []
        if reserved_tokens is None:
            reserved_tokens = []
        # 按出现频率排序
        counter = collections.Counter([token for line in tokens for token in line])
        self._token_freqs = sorted(counter.items(), key=lambda x: x[1],
                                   reverse=True)
        # 未知词元的索引为0
        self.idx_to_token = ['<unk>'] + reserved_tokens
        self.token_to_idx = {token: idx
                             for idx, token in enumerate(self.idx_to_token)}
        for token, freq in self._token_freqs:
            if freq < min_freq:
                break
            if token not in self.token_to_idx:
                self.idx_to_token.append(token)
                self.token_to_idx[token] = len(self.idx_to_token) - 1

    def __len__(self):
        return len(self.idx_to_token)

    def __getitem__(self, tokens):
        if not isinstance(tokens, (list, tuple)):
            return self.token_to_idx.get(tokens, self.unk)
        return [self.__getitem__(token) for token in tokens]

    def to_tokens(self, indices):
        if not isinstance(indices, (list, tuple)):
            return self.idx_to_token[indices]
        return [self.idx_to_token[index] for index in indices]

    @property
    def unk(self):  # 未知词元<unk>的索引为0
        return 0

    @property
    def token_freqs(self):
        return self._token_freqs

def load_corpus_time_machine(max_tokens=-1):
    """返回时光机器数据集的词元索引列表和词表"""
    lines = read_time_machine()
    tokens = tokenize(lines, 'char')
    vocab = Vocab(tokens)
    # 因为时光机器数据集中的每个文本行不一定是一个句子或一个段落，
    # 所以将所有文本行展平到一个列表中
    corpus = [vocab[token] for line in tokens for token in line]  # 这里将字符转换为索引
    if max_tokens > 0:
        corpus = corpus[:max_tokens]
    return corpus, vocab

# 数据迭代器相关函数
def seq_data_iter_random(corpus, batch_size, num_steps):
    """使用随机抽样生成一个小批量子序列"""
    # 从随机偏移量开始划分序列
    corpus = corpus[random.randint(0, num_steps):]
    # 减去1，是因为我们需要考虑标签
    num_subseqs = (len(corpus) - 1) // num_steps
    # 长度为num_steps的子序列的起始索引
    initial_indices = list(range(0, num_subseqs * num_steps, num_steps))
    # 在随机抽样的迭代过程中，
    # 来自两个相邻的、随机的、小批量中的子序列
    # 不一定在原始序列上相邻
    random.shuffle(initial_indices)

    def data(pos):
        # 返回从pos位置开始的长度为num_steps的序列
        return corpus[pos: pos + num_steps]

    num_batches = num_subseqs // batch_size
    for i in range(0, batch_size * num_batches, batch_size):
        # 在这里，initial_indices包含子序列的随机起始索引
        initial_indices_per_batch = initial_indices[i: i + batch_size]
        X = [data(j) for j in initial_indices_per_batch]
        Y = [data(j + 1) for j in initial_indices_per_batch]
        yield tf.constant(X, dtype=tf.int32), tf.constant(Y, dtype=tf.int32)

class SeqDataLoader:
    """加载序列数据的迭代器"""
    def __init__(self, batch_size, num_steps, use_random_iter, max_tokens):
        if use_random_iter:
            self.data_iter_fn = seq_data_iter_random
        else:
            self.data_iter_fn = seq_data_iter_random  # 简化处理
        self.corpus, self.vocab = load_corpus_time_machine(max_tokens)
        self.batch_size, self.num_steps = batch_size, num_steps

    def __iter__(self):
        return self.data_iter_fn(self.corpus, self.batch_size, self.num_steps)

def load_data_time_machine(batch_size, num_steps, use_random_iter=False, max_tokens=10000):
    """返回时光机器数据集的迭代器和词表"""
    data_iter = SeqDataLoader(batch_size, num_steps, use_random_iter, max_tokens)
    return data_iter, data_iter.vocab

# 现代RNN模型实现
class ModernRNNModel(tf.keras.Model):
    """使用TensorFlow现代API实现的RNN模型"""
    def __init__(self, vocab_size, num_hiddens, **kwargs):
        super(ModernRNNModel, self).__init__(**kwargs)
        self.num_hiddens = num_hiddens
        self.vocab_size = vocab_size
        
        # 使用SimpleRNN层
        self.rnn = tf.keras.layers.SimpleRNN(
            num_hiddens,
            return_sequences=True,
            return_state=True,
            # 初始化参数
            kernel_initializer='glorot_uniform',  # 输入到隐藏层权重初始化
            recurrent_initializer='orthogonal',   # 隐藏层到隐藏层权重初始化
            bias_initializer='zeros'              # 偏置初始化
        )
        # 输出层
        self.dense = tf.keras.layers.Dense(
            vocab_size,
            kernel_initializer='glorot_uniform',  # 输出层权重初始化
            bias_initializer='zeros'              # 输出层偏置初始化
        )

    def call(self, inputs, state=None, training=None):
        # 确保输入是正确的整数类型
        inputs = tf.cast(inputs, tf.int32)
        # inputs形状: (batch_size, num_steps)
        X = tf.one_hot(inputs, self.vocab_size)
        # X形状: (batch_size, num_steps, vocab_size)
        
        # 如果没有提供初始状态，则初始化为零
        if state is None:
            state = self.begin_state(X.shape[0])
        
        # 通过RNN层
        Y, state = self.rnn(X, initial_state=state, training=training)
        # Y形状: (batch_size, num_steps, num_hiddens)
        
        # 通过输出层
        output = self.dense(tf.reshape(Y, (-1, Y.shape[-1])), training=training)
        # output形状: (batch_size * num_steps, vocab_size)
        
        return output, state

    def begin_state(self, batch_size):
        """初始化隐藏状态"""
        return tf.zeros((batch_size, self.num_hiddens))

# 梯度裁剪函数
def grad_clipping(grads, theta):
    """裁剪梯度以防止梯度爆炸"""
    theta = tf.constant(theta, dtype=tf.float32)
    new_grad = []
    for grad in grads:
        if isinstance(grad, tf.IndexedSlices):
            new_grad.append(tf.convert_to_tensor(grad))
        else:
            new_grad.append(grad)
    norm = tf.linalg.global_norm(new_grad)
    if norm > theta:
        new_grad = [grad * theta / norm for grad in new_grad]
    return new_grad

# 预测函数 - 修复版本
def predict(prefix, num_preds, net, vocab):
    """在prefix后面生成新字符"""
    state = net.begin_state(batch_size=1)
    outputs = [vocab[prefix[0]]]
    
    # 预热期 - 处理前缀中的每个字符
    for y in prefix[1:]:
        # 创建输入张量
        input_tensor = tf.constant([[outputs[-1]]], dtype=tf.int32)
        # 前向传播
        _, state = net(input_tensor, state)
        outputs.append(vocab[y])
    
    # 预测期 - 生成新字符
    for _ in range(num_preds):
        # 创建输入张量
        input_tensor = tf.constant([[outputs[-1]]], dtype=tf.int32)
        # 前向传播
        y_pred, state = net(input_tensor, state)
        # 选择概率最高的字符
        next_char = int(tf.argmax(y_pred, axis=1).numpy()[0])
        outputs.append(next_char)
    
    # 将索引转换为字符
    result = ''.join([vocab.idx_to_token[i] for i in outputs])
    return result

# 训练函数 - 修复版本
def train_epoch(net, train_iter, loss, optimizer, clip_norm=1.0):
    """训练模型一个迭代周期"""
    total_loss = 0
    num_batches = 0
    
    for X, Y in train_iter:
        # 确保输入是正确的整数类型
        X = tf.cast(X, tf.int32)
        Y = tf.cast(Y, tf.int32)
        
        with tf.GradientTape() as tape:
            # 前向传播
            y_pred, _ = net(X, training=True)
            # 重塑Y以匹配y_pred的形状 - 修复标签形状
            y_true = tf.reshape(Y, (-1,))
            # 计算损失
            l = loss(y_true, y_pred)
        
        # 计算梯度
        grads = tape.gradient(l, net.trainable_variables)
        # 梯度裁剪
        if clip_norm > 0:
            grads = grad_clipping(grads, clip_norm)
        # 应用梯度更新
        optimizer.apply_gradients(zip(grads, net.trainable_variables))
        
        total_loss += l.numpy()
        num_batches += 1
    
    return total_loss / num_batches if num_batches > 0 else 0

def train(net, train_iter, vocab, num_epochs, learning_rate, clip_norm=1.0):
    """训练模型"""
    # 损失函数
    loss = tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True)
    # 优化器 - 使用更小的学习率
    optimizer = tf.keras.optimizers.SGD(learning_rate)
    
    print("开始训练...")
    for epoch in range(num_epochs):
        loss_val = train_epoch(net, train_iter, loss, optimizer, clip_norm)
        if (epoch + 1) % 10 == 0:
            print(f'epoch {epoch+1}, loss {loss_val:.4f}')
            # 尝试预测
            try:
                pred = predict('time', 10, net, vocab)
                print(f'预测示例: {pred}')
            except Exception as e:
                print(f"预测出错: {e}")

# 主程序 - 使用更好的超参数
if __name__ == '__main__':
    # 设置超参数 - 优化后的参数
    batch_size, num_steps = 32, 35
    num_hiddens = 256  # 增加隐藏单元数
    max_tokens = 10000
    num_epochs = 500
    learning_rate = 0.5  # 降低学习率
    clip_norm = 5.0  # 增加梯度裁剪阈值
    
    # 加载数据
    train_iter, vocab = load_data_time_machine(
        batch_size, num_steps, 
        use_random_iter=True, 
        max_tokens=max_tokens
    )
    
    # 创建模型
    net = ModernRNNModel(len(vocab), num_hiddens)
    
    # 构建模型（通过一次前向传播）
    for X, Y in train_iter:
        X = tf.cast(X, tf.int32)
        net(X)
        break
    
    # 打印模型信息
    print(f"词汇表大小: {len(vocab)}")
    print(f"隐藏单元数: {num_hiddens}")
    print("模型参数初始化完成")
    
    # 训练模型
    train(net, train_iter, vocab, num_epochs, learning_rate, clip_norm)
    
    # 测试预测
    print("\n最终预测结果:")
    for i in range(5):
        try:
            pred = predict('time', 20, net, vocab)
            print(f'预测 {i+1}: {pred}')
        except Exception as e:
            print(f"预测出错: {e}")