#include <stdio.h>
#include <stdlib.h>
//linked queue�� �̿��Ͽ� bfs�� ����ϰ� �����غ��ڽ��ϴ�.

typedef struct Node{
    struct Node *left;
    struct Node *right;
    int data;
    struct Node *queue_pointer;
}Node;


void append(Node *pointer, int input);
void showTree(Node *pointer);
void freeTree(Node *pointer);



int main()
{
    Node *head = malloc(sizeof(Node));
    head->left = NULL;
    head->right = NULL;
    head->queue_pointer = NULL;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    append(head, 70);
    append(head, 80);
    append(head, 90);
    append(head, 100);
    append(head, 110);
    append(head, 120);
    append(head, 130);
    append(head, 140);
    showTree(head);
    freeTree(head);

    return 0;
}

void append(Node *pointer, int input)
{
    Node *tmp = pointer;
    Node *last_node = pointer;//���� �������� ��ġ�� node�� ã�� ���� ����ü
    Node* newNode = malloc(sizeof(Node));

    while(last_node->queue_pointer != NULL)
    {
        last_node = last_node->queue_pointer;
    }

    while(1)
    {
        if(tmp->left == NULL)
        {
            newNode->data = input;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->queue_pointer = NULL;
            tmp->left = newNode;
            last_node->queue_pointer = newNode;
            break;
        }

        else if(tmp->right == NULL)
        {
            newNode->data = input;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->queue_pointer = NULL;
            tmp->right = newNode;
            last_node->queue_pointer = newNode;
            break;
        }

        else
        {
            tmp = tmp->queue_pointer;
        }
    }
}

void showTree(Node *pointer)
{
    Node *tmp = pointer;
    int count = 0;
    while(tmp != NULL)
    {
        //printf("%d�� node�� data: %d\n",count, tmp->data);
        printf("%d�� node�� �ּҰ�: %p\n",count, tmp);
        // printf("%d�� node�� left node data: %d\n",count, tmp->left->data);
        // printf("%d�� node�� right node data: %d\n",count, tmp->right->data);
        // printf("%d�� node�� ���� queue�� data: %d\n",count, tmp->queue_pointer->data);
        printf("%d�� node�� ���� queue�� �ּҰ�: %p\n\n",count, tmp->queue_pointer);
        tmp = tmp->queue_pointer;
        count++;
    }
    printf("\n");
}

void freeTree(Node *pointer)
{
    Node *tmp = pointer;
    Node *alive;
    int count = 0;
    while(tmp != 0)
    {
        alive = tmp->queue_pointer;
        free(tmp);
        tmp = alive;
        count++;
        printf("%dȸ free�Ǿ����ϴ�.\n",count);
    }
    printf("\n�����ϼ̽��ϴ�\n");
}
