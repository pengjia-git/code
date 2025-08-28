#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// 模拟内核中的 hlist 结构
struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

// 初始化哈希链表头
#define INIT_HLIST_HEAD(ptr) ((ptr)->first = NULL)

// 添加节点到链表头部
static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {
    struct hlist_node *first = h->first;
    n->next = first;
    if (first)
        first->pprev = &n->next;
    h->first = n;
    n->pprev = &h->first;
}

// 删除节点
static inline void hlist_del(struct hlist_node *n) {
    struct hlist_node *next = n->next;
    struct hlist_node **pprev = n->pprev;
    *pprev = next;
    if (next)
        next->pprev = pprev;
}

// 遍历宏
#define hlist_for_each_entry(pos, head, member) \
    for (pos = hlist_entry_safe((head)->first, typeof(*pos), member); \
         pos; \
         pos = hlist_entry_safe(pos->member.next, typeof(*pos), member))

#define hlist_entry_safe(ptr, type, member) \
    ({ typeof(ptr) ____ptr = (ptr); \
       ____ptr ? container_of(____ptr, type, member) : NULL; })

#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) );})

// 示例数据结构
struct person {
    int id;
    char name[32];
    struct hlist_node node;
};

int main() {
    #define HASH_SIZE 4
    struct hlist_head hashtable[HASH_SIZE];
    
    // 初始化哈希表
    for (int i = 0; i < HASH_SIZE; i++) {
        INIT_HLIST_HEAD(&hashtable[i]);
    }
    
    // 创建测试数据
    struct person p1 = {.id = 1, .name = "Alice"};
    struct person p2 = {.id = 2, .name = "Bob"};
    struct person p3 = {.id = 3, .name = "Charlie"};
    struct person p4 = {.id = 4, .name = "David"};
    
    // 添加到哈希表（简单哈希函数：id % HASH_SIZE）
    hlist_add_head(&p1.node, &hashtable[p1.id % HASH_SIZE]);
    hlist_add_head(&p2.node, &hashtable[p2.id % HASH_SIZE]);
    hlist_add_head(&p3.node, &hashtable[p3.id % HASH_SIZE]);
    hlist_add_head(&p4.node, &hashtable[p4.id % HASH_SIZE]);
    
    // 遍历并打印哈希表
    printf("=== Hash Table Contents ===\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("Bucket %d:", i);
        struct person *pos;
        hlist_for_each_entry(pos, &hashtable[i], node) {
            printf(" -> [%d: %s]", pos->id, pos->name);
        }
        printf("\n");
    }
    
    // 删除节点2
    hlist_del(&p2.node);
    
    // 再次打印结果
    printf("\n=== After deleting Bob (id=2) ===\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("Bucket %d:", i);
        struct person *pos;
        hlist_for_each_entry(pos, &hashtable[i], node) {
            printf(" -> [%d: %s]", pos->id, pos->name);
        }
        printf("\n");
    }
    
    return 0;
}
