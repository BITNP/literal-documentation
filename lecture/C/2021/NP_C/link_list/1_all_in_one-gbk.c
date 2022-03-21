/**
 * @file 1_all_in_one.c
 * @author ��Ԫ��
 * @brief ��ͷ���ģ���������
 * @version 0.1
 * @date 2021-06-07
 * 
 * ���޷�ȫ������ֻ���� Initialize()��PushFront()��PrintAll()
 * �� DeleteAll() �ɡ�����Ȼ������������
 * ��Щ������ע�͡����У�һ��ֻ�� 40 ���С�
 * 
 * �ԡ�/**����ͷ��ע�ͻ������֮��ĺ�����
 * ������˵��@brief �ǹ��ܼ�飬@param ������ʽ������@return ���ܷ���ֵ��
 * 
 * ���⣬Ϊ��ѭ�򽥽�������д��Щ�ظ����򣬼��¡�
 * 
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

/**
 * @brief ���������ڴ沢��ʼ��
 * 
 * @return Node* ��ʼ����Ľ��
 */
Node *Initialize()
{
    // �����Ա���Щ��д��������ʱһ��ֱ��д malloc() ���С�
    /* Node *node = NULL;
    while (node == NULL)
        node = (Node *)malloc(sizeof(Node)); */

    Node *node = (Node *)malloc(sizeof(Node));

    node->data = Undefined;
    node->next = NULL;

    return node;
}

/**
 * @brief ������ͷ������
 * 
 * @param head ����ͷ
 * @param data �½�������
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
 * @brief �������������
 * 
 * @param head ����ͷ
 */
void PrintAll(Node *head)
{
    assert(head != NULL);

    printf("[");
    head = head->next;

    // ������ǵ�һ�μ� bool��true��false�����������ǵ��� int��1��0��
    // ������Ҫ #include <stdbool.h> ��
    bool is_first = true; // �Ƿ��ǵ�һ�����
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
 * @brief ɾ����������
 * �� free() ��ָ�붼�ͷŵ���
 * @param head ����ͷ
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

void Test(); // �����뿴������������������С�

int main()
{
    Node *head = Initialize();

    for (int i = 0; i < 5; i++)
        PushFront(head, i);

    printf("�׸���㣺%d��\n", head->next->data);
    PrintAll(head);

    DeleteAll(head);

    return 0;
}

// --- ��������������뿴������ ---

/**
 * @brief �������β׷�ӽ��
 * 
 * @param head ����ͷ
 * @param data �½�������
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
 * @brief ����������
 * 
 * @param head ����ͷ
 * @return int ����
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
 * @brief ������
 * 
 * @param ref ����λ�õ�ǰһ����㣬���½����� ref ����һ�����
 * @param data �½�������
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
 * @brief Ѱ�ҽ��
 * 
 * @param head ����ͷ
 * @param pos �������λ��
 * ������ʾ��ǰ����������ʾ�Ӻ�����
 * 1 ��ʾ��һ����㣬len(head) �� -1 ��ʾ���һ����㣬0 ��ʾ����ͷ��
 * @return Node* �����㣬ʧ��ʱΪ NULL
 */
Node *FindAt(Node *head, int pos)
{
    assert(head != NULL);

    if (pos < 0)
        pos += len(head) + 1;
    if (pos < 0)
        return NULL; // pos ����̫�࣬��������

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
 * @param head ����ͷ
 * @param pos ��������λ��
 * ������ʾ��ǰ����������ʾ�Ӻ�����
 * �涨�� FindAt() ��ͬ��ȡ 0 �൱�� PushFront()��ȡ len(head) �൱�� PushBack()��
 * -1 ��ʾ����λ��Ϊ������ǰ������ģ����һ����㣨�½�����ڲ���������ĵ����ڶ�������
 * @param data �½�������
 * @return int ���ʾ�ɹ��������ʾʧ��
 */
int InsertAt(Node *head, int pos, Data data)
{
    assert(head != NULL);

    if (pos < 0)
        pos += len(head);
    if (pos < 0)
        return 1; // pos ����̫�࣬��������

    Node *prefix = head; // pos ��Ӧ����ǰһ���

    int count = 0;
    while (prefix != NULL && count < pos) {
        prefix = prefix->next;
        count++;
    }
    if (prefix == NULL)
        return 2; // pos ̫�󣬳�����������

    InsertAfter(prefix, data);

    return 0;
}

/**
 * @brief ɾ����ǰ��Ľ�㲢��������
 * 
 * @param head ����ͷ
 * @return Data �ý�������
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
 * @brief ɾ����������
 * ��һ�ַ�����
 * @param head ����ͷ
 */
void DeleteAll2(Node *head)
{
    assert(head != NULL);

    while (head->next != NULL)
        PopFront(head);
    free(head);
}

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

/**
 * @brief ɾ�����
 * 
 * @param head ����ͷ
 * @param pos ɾ������λ��
 * ������ʾ��ǰ����������ʾ�Ӻ�����
 * �涨�� FindAt() ��ͬ��ֻ�ǲ�����ȡ 0��
 * @return Data Ҫɾ���Ľ�������
 */
Data DeleteAt(Node *head, int pos)
{
    if (pos == 0)
        return Undefined;

    Node *prefix = FindAt(head, pos - 1);
    return DeleteAfter(prefix);
    // prefix == NULL ʱ DeleteAfter() �ᴦ��
}

/* ����� HandleDataFunc��Traverse() ��ͨ�õı���������
 * PrintData() �������������ġ��������� Test() ������������У�
 * Traverse(head, PrintData);
 * ����ƽʱ���������Ƶ�ѡ����ҵ�������Թ��Ʋ��ῼ�����Ŭ�������ˣ��ǻ��а����ġ�
 */
// ���� data �ĺ���
typedef void (*HandleDataFunc)(Data);
/**
 * @brief ����
 * 
 * @param head ����ͷ
 * @param handle ���� data �ĺ���
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
 * @brief ������Щ��ʾ��
 * ��������������á�������㿴������仰��
 */
void Test()
{
    Node *head = Initialize();

    puts("���������� 5 ������ >> ");
    Data data;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &data);
        PushFront(head, data);
    }
    InsertAt(head, -1, 233);
    PushBack(head, 23333);

    PrintAll(head);
    printf("����: %d��\n\n", len(head));

    Data front = PopFront(head);
    printf("�׸���㣺%d��\n", front);
    printf("��ʱ���� %d���������£�\n", len(head));
    PrintAll(head);

    // puts("������");
    // Traverse(head, PrintData);

    DeleteAll2(head);
}
