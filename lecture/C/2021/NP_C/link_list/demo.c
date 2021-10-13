#include <stdbool.h>
#include <stdio.h>

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

void struct_of_nodes()
{
    Node *next_node;

    Node *head = (Node *)malloc(sizeof(Node));
    head->data = Undefined;
    head->next = NULL;
    // head->next = next_node;

    Node *last_node;
    Data some_data;
    last_node->data = some_data;
    last_node->next = NULL;
}

Node *Initialize()
{
    Node *node = (Node *)malloc(sizeof(Node));

    node->data = Undefined;
    node->next = NULL;

    return node;
}

void PrintAll(Node *head)
{
    head = head->next;
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

/**
 * @brief 寻找结点
 * 
 * @param head 链表头
 * @param pos 待求结点的位置，1 表示第一个结点
 * @return Node* 待求结点，失败时为 NULL
 */
Node *FindAt(Node *head, int pos)
{
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
 * @param ref 插入位置的前一个结点，即新结点会是 ref 的下一个结点
 * @param data 新结点的数据
 */
void InsertAfter(Node *ref, Data data)
{
    // 新结点
    Node *new_node = Initialize();
    new_node->data = data;
    new_node->next = ref->next;

    // 修改关系
    ref->next = new_node;
}

void InsertAt(Node *head, int pos, Data data);

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

int main()
{
    Node *head = Initialize();
    /* ... */

    printf("首个结点：%d。\n",
           head->next->data);

    return 0;
}
