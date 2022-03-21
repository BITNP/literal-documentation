/**
 * @file 1_all_in_one.c
 * @author 徐元昌
 * @brief 带头结点的（单向）链表
 * @version 0.1
 * @date 2021-06-07
 * 
 * 若无法全看，就只看看 Initialize()、PushFront()、PrintAll()
 * 和 DeleteAll() 吧。（当然还有主函数）
 * 这些若不算注释、空行，一共只有 40 多行。
 * 
 * 以“/**”开头的注释会解释它之后的函数：
 * 具体来说，@brief 是功能简介，@param 介绍形式参数，@return 介绍返回值。
 * 
 * 另外，为了循序渐进，故意写了些重复程序，见谅。
 * 
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 用于存储数据的类型，这里相当于 int
typedef int Data;
// 未定义值，用于链表头结点的 data 等
#define Undefined -1

struct _Node {
    Data data;          // 数据
    struct _Node *next; // 指向下一结点的指针
};
// 链表的结点
typedef struct _Node Node;

/**
 * @brief 给结点分配内存并初始化
 * 
 * @return Node* 初始化后的结点
 */
Node *Initialize()
{
    // 这是略保险些的写法，考试时一般直接写 malloc() 就行。
    /* Node *node = NULL;
    while (node == NULL)
        node = (Node *)malloc(sizeof(Node)); */

    Node *node = (Node *)malloc(sizeof(Node));

    node->data = Undefined;
    node->next = NULL;

    return node;
}

/**
 * @brief 在链表开头插入结点
 * 
 * @param head 链表头
 * @param data 新结点的数据
 */
void PushFront(Node *head, Data data)
{
    assert(head != NULL);

    Node *new_node = Initialize();
    new_node->data = data;
    new_node->next = head->next;

    head->next = new_node;
}

/**
 * @brief 遍历并输出数据
 * 
 * @param head 链表头
 */
void PrintAll(Node *head)
{
    assert(head != NULL);

    printf("[");
    head = head->next;

    // 如果你是第一次见 bool、true、false，不妨把它们当作 int、1、0。
    // 它们需要 #include <stdbool.h> 。
    bool is_first = true; // 是否是第一个结点
    while (head != NULL) {
        if (is_first)
            is_first = false;
        else
            printf(", ");

        printf("%d", head->data);
        head = head->next;
    }

    puts("]");
}

/**
 * @brief 删除整个链表
 * 用 free() 把指针都释放掉。
 * @param head 链表头
 */
void DeleteAll(Node *head)
{
    assert(head != NULL);

    Node *delete_node = head,
         *next_node = head->next;

    while (next_node != NULL) {
        free(delete_node);
        delete_node = next_node;

        next_node = next_node->next;
    }

    free(delete_node);
}

void Test(); // 若不想看其它函数，请忽略这行。

int main()
{
    Node *head = Initialize();

    for (int i = 0; i < 5; i++)
        PushFront(head, i);

    printf("首个结点：%d。\n", head->next->data);
    PrintAll(head);

    DeleteAll(head);

    return 0;
}

// --- 其它函数如果不想看就算了 ---

/**
 * @brief 在链表结尾追加结点
 * 
 * @param head 链表头
 * @param data 新结点的数据
 */
void PushBack(Node *head, Data data)
{
    assert(head != NULL);

    while (head->next != NULL)
        head = head->next;

    Node *new_node = Initialize();
    new_node->data = data;
    new_node->next = NULL;

    head->next = new_node;
}

/**
 * @brief 计算链表长度
 * 
 * @param head 链表头
 * @return int 长度
 */
int len(Node *head)
{
    assert(head != NULL);

    int ret = 0;
    while (head->next != NULL) {
        head = head->next;
        ret++;
    }
    return ret;
}

/**
 * @brief 插入结点
 * 
 * @param ref 插入位置的前一个结点，即新结点会是 ref 的下一个结点
 * @param data 新结点的数据
 */
void InsertAfter(Node *ref, Data data)
{
    assert(ref != NULL);

    Node *new_node = Initialize();
    new_node->data = data;
    new_node->next = ref->next;

    ref->next = new_node;
}

/**
 * @brief 寻找结点
 * 
 * @param head 链表头
 * @param pos 待求结点的位置
 * 正数表示从前数，负数表示从后数。
 * 1 表示第一个结点，len(head) 或 -1 表示最后一个结点，0 表示链表头。
 * @return Node* 待求结点，失败时为 NULL
 */
Node *FindAt(Node *head, int pos)
{
    assert(head != NULL);

    if (pos < 0)
        pos += len(head) + 1;
    if (pos < 0)
        return NULL; // pos 负得太多，无意义了

    Node *ret = head;

    int count = 0;
    while (ret != NULL && count < pos) {
        ret = ret->next;
        count++;
    }
    return ret;
}

/**
 * @brief 插入结点
 * 
 * @param head 链表头
 * @param pos 插入后结点的位置
 * 正数表示从前数，负数表示从后数。
 * 规定与 FindAt() 不同：取 0 相当于 PushFront()，取 len(head) 相当于 PushBack()，
 * -1 表示插入位置为（插入前的链表的）最后一个结点（新结点是在插入后的链表的倒数第二个）。
 * @param data 新结点的数据
 * @return int 零表示成功，非零表示失败
 */
int InsertAt(Node *head, int pos, Data data)
{
    assert(head != NULL);

    if (pos < 0)
        pos += len(head);
    if (pos < 0)
        return 1; // pos 负得太多，无意义了

    Node *prefix = head; // pos 对应结点的前一结点

    int count = 0;
    while (prefix != NULL && count < pos) {
        prefix = prefix->next;
        count++;
    }
    if (prefix == NULL)
        return 2; // pos 太大，超出链表长度了

    InsertAfter(prefix, data);

    return 0;
}

/**
 * @brief 删除最前面的结点并返回数据
 * 
 * @param head 链表头
 * @return Data 该结点的数据
 */
Data PopFront(Node *head)
{
    assert(head != NULL);
    if (head->next == NULL)
        return Undefined;

    Node *delete_node = head->next;
    head->next = delete_node->next;
    Data ret = delete_node->data;

    free(delete_node);

    return ret;
}

/**
 * @brief 删除整个链表
 * 另一种方法。
 * @param head 链表头
 */
void DeleteAll2(Node *head)
{
    assert(head != NULL);

    while (head->next != NULL)
        PopFront(head);
    free(head);
}

/**
 * @brief 删除结点
 * 
 * @param ref 删除位置的前一个结点
 * @return Data 要删除的结点的数据
 */
Data DeleteAfter(Node *ref)
{
    if (ref == NULL || ref->next == NULL)
        return Undefined;

    Node *delete_node = ref->next;
    Data ret = delete_node->data;
    ref->next = delete_node->next;

    free(delete_node);

    return ret;
}

/**
 * @brief 删除结点
 * 
 * @param head 链表头
 * @param pos 删除结点的位置
 * 正数表示从前数，负数表示从后数。
 * 规定与 FindAt() 相同，只是不允许取 0。
 * @return Data 要删除的结点的数据
 */
Data DeleteAt(Node *head, int pos)
{
    if (pos == 0)
        return Undefined;

    Node *prefix = FindAt(head, pos - 1);
    return DeleteAfter(prefix);
    // prefix == NULL 时 DeleteAfter() 会处理
}

/* 下面的 HandleDataFunc、Traverse() 是通用的遍历函数，
 * PrintData() 是用来测试它的——试试在 Test() 里加上下面这行？
 * Traverse(head, PrintData);
 * 尽管平时可能有类似的选做作业，但考试估计不会考；如果努力看懂了，是会有帮助的。
 */
// 处理 data 的函数
typedef void (*HandleDataFunc)(Data);
/**
 * @brief 遍历
 * 
 * @param head 链表头
 * @param handle 处理 data 的函数
 */
void Traverse(Node *head, HandleDataFunc handle)
{
    assert(head != NULL);

    head = head->next;
    while (head != NULL) {
        handle(head->data);
        head = head->next;
    }
}

void PrintData(Data data)
{
    if (data != Undefined)
        printf(" -> %d", data);
    else
        printf(" -> (Undefined)");
}

/**
 * @brief 稍完整些的示例
 * 请在主函数里调用。（如果你看到了这句话）
 */
void Test()
{
    Node *head = Initialize();

    puts("现在请输入 5 个数据 >> ");
    Data data;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &data);
        PushFront(head, data);
    }
    InsertAt(head, -1, 233);
    PushBack(head, 23333);

    PrintAll(head);
    printf("长度: %d。\n\n", len(head));

    Data front = PopFront(head);
    printf("首个结点：%d。\n", front);
    printf("此时链表长 %d，具体如下：\n", len(head));
    PrintAll(head);

    // puts("遍历：");
    // Traverse(head, PrintData);

    DeleteAll2(head);
}
