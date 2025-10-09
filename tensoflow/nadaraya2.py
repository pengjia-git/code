import numpy as np
def true_attention_example():
    """
    展示Nadaraya-Watson在真正注意力任务中的应用
    """
    
    # 文档摘要任务：从长文档中提取重要句子
    document_sentences = [
        "深度学习是机器学习的一个分支。",
        "它使用多层神经网络来学习数据的层次化表示。", 
        "注意力机制让模型能够关注输入的重要部分。",
        "Transformer模型基于自注意力机制。",
        "这些技术在现代NLP中广泛应用。"
    ]
    
    # 句子编码（简化）
    sentence_embeddings = np.array([
        [0.9, 0.1, 0.0],  # 深度学习相关
        [0.8, 0.2, 0.0],  # 神经网络相关
        [0.1, 0.9, 0.0],  # 注意力相关  
        [0.0, 0.8, 0.2],  # Transformer相关
        [0.1, 0.1, 0.8]   # 应用相关
    ])
    
    # 查询：用户想知道"什么是注意力机制"
    query_embedding = np.array([0.0, 1.0, 0.0])  # 注意力机制相关
    
    print("文档句子:")
    for i, sent in enumerate(document_sentences):
        print(f"{i+1}. {sent}")
    
    print(f"\n用户查询: '什么是注意力机制'")
    print(f"查询向量: {query_embedding}")
    
    # Nadaraya-Watson注意力计算
    similarities = []
    for i, embedding in enumerate(sentence_embeddings):
        # 计算查询与每个句子的相似度
        similarity = np.dot(query_embedding, embedding)  # 点积相似度
        similarities.append(similarity)
        print(f"与句子{i+1}相似度: {similarity:.3f}")
    
    # 注意力权重（softmax）
    attention_weights = np.exp(similarities) / np.sum(np.exp(similarities))
    
    print(f"\n注意力权重分布:")
    for i, (sent, weight) in enumerate(zip(document_sentences, attention_weights)):
        print(f"句子{i+1}: {weight:.3f} - {sent}")
    
    # 最相关的句子（注意力最高的）
    most_attended = np.argmax(attention_weights)
    print(f"\n最相关的回答: '{document_sentences[most_attended]}'")
    
    return attention_weights

# 运行真正的注意力例子
true_attention_example()