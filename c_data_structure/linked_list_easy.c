#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *Pointer;
    int data;
};

//linked_list �ϳ��� ���� ����غ���

int main()
{
    struct Node *head = malloc(sizeof(struct Node));

    struct Node *node1 = malloc(sizeof(struct Node));
    head->Pointer = node1;
    node1->data = 10;

    struct Node *node2 = malloc(sizeof(struct Node));
    node1->Pointer = node2;
    node2->data = 20;

    struct Node *node3 = malloc(sizeof(struct Node));
    node2->Pointer = node3;
    node3->data = 30;
    node3->Pointer = NULL;

    printf("node1�� data �����ϱ�\n");
    printf("1. head�� ����: %d, 2. node1���� ����: %d\n\n",head->Pointer->data, node1->data);
    printf("node2�� data �����ϱ�\n");
    printf("1. head�� ����: %d, 2. node1���� ����: %d, 3. node2�� ����: %d\n\n",head->Pointer->Pointer->data, node1->Pointer->data, node2->data);
    printf("node3�� data �����ϱ�\n");
    printf("1. head�� ����: %d, 2. node1���� ����: %d, 3. node2�� ����: %d, 4. node3���� ����: %d\n\n",head->Pointer->Pointer->Pointer->data, node1->Pointer->Pointer->data, node2->Pointer->data, node3->data);

    struct Node *test = head->Pointer;//�ݺ����� ����ϱ� ���� ���ο� ������ ����?

    while(test != NULL)//����� ��� node�� data�� ������� ����ϴ� �ݺ���
    {
        printf("%d\n",test->data);
        test = test->Pointer;
    }

    free(node3);
    free(node2);
    free(node1);
    free(head);

    
    return 0;
}