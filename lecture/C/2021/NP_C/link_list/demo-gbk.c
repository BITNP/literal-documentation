#include <stdbool.h>
#include <stdio.h>

// ���ڴ洢���ݵ����ͣ������൱�� int
typedef int Data;
// δ����ֵ����������ͷ���� data ��
#define Undefined -1

struct _Node {
    Data data;          // ����
    struct _Node *next; // ָ����һ����ָ��
};
// ����Ľ��
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
 * @brief Ѱ�ҽ��
 * 
 * @param head ����ͷ
 * @param pos �������λ�ã�1 ��ʾ��һ�����
 * @return Node* �����㣬ʧ��ʱΪ NULL
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
 * @brief ������
 * 
 * @param ref ����λ�õ�ǰһ����㣬���½����� ref ����һ�����
 * @param data �½�������
 */
void InsertAfter(Node *ref, Data data)
{
    // �½��
    Node *new_node = Initialize();
    new_node->data = data;
    new_node->next = ref->next;

    // �޸Ĺ�ϵ
    ref->next = new_node;
}

void InsertAt(Node *head, int pos, Data data);

/**
 * @brief ɾ�����
 * 
 * @param ref ɾ��λ�õ�ǰһ�����
 * @return Data Ҫɾ���Ľ�������
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

    printf("�׸���㣺%d��\n",
           head->next->data);

    return 0;
}
