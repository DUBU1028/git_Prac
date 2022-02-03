#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    struct Node *next;
    int data;
}Node;

void append(Node *list, int data); //list�� �Ǹ����� node�ڿ� ���ο� node ����
void showList(Node *list);//���� list ���� node���� data�� ����(head����)
void deleteList(Node *list);//list ���� node���� �����ϸ� �޸� �Ҵ��� free��Ŵ
void getNodeLength(Node *list);// list�� node ���� ���(head ����)
void insert(Node *list, int order, int data);// list�� Ư�� ������ ���ο� node�� �߰�(head�� ������ node����)
void swapNodeData_specific(Node *list, int order1, int order2);// list���� Ư�� �� node�� data�� �ٲ�(head�� ������ node����)


int main()
{
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    printf("****linked list test!****\n");
    while(1)
    {
        int choice;
        int data = 0;
        int order1 = 0;
        int order2 = 0;
        printf("1. append, 2. showList, 3. getNodeLength, 4. insert, 5. swapNodeData_specific, 6. deleteList and exit\n");
        printf("���ڸ� �Է��Ͻʽÿ�: ");
        scanf("%d",&choice);

        switch(choice){

            case 1 :
                printf("�߰��� ���ڸ� �Է��Ͻʽÿ�: ");
                scanf("%d",&data);
                printf("\n\n");
                append(head, data);
                break;
            
            case 2 :
                showList(head);
                printf("\n");
                break;
            
            case 3 :
                getNodeLength(head);
                printf("\n");
                break;
            
            case 4 :
                printf("�߰��� ��ġ�� ���ڸ� �Է��Ͻʽÿ�: ");
                scanf("%d %d",&order1, &data);
                insert(head, order1, data);
                printf("\n");
                break;
            
            case 5:
                printf("������ �� Node�� ��ġ�� �Է��Ͻʽÿ�: ");
                scanf("%d %d",&order1, &order2);
                swapNodeData_specific(head, order1, order2);
                printf("\n");
                break;

            case 6 :
                deleteList(head);
                return 0;
            
            default :
                printf("��ȿ�� ���ڸ� �Է����ֽʽÿ�\n\n");
            
        } 
    }
    return 0;
}

void append(Node *list, int data)
{
    Node *tmp = list;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    Node *NewNode = malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->next = NULL;
    tmp->next = NewNode;
}

void showList(Node *list)
{
    int count=1;
    Node *tmp = list;
    printf("head�� data: %d\n",tmp->data);
    tmp= tmp->next;
    while(tmp != NULL)
    {
        printf("%d�� node�� data: %d\n",count, tmp->data);
        tmp = tmp->next;
        count++;
    }
}

void deleteList(Node *list)
{
    int count=1;
    Node *tmp = list;
    Node *alive;
    while(tmp != NULL)
    {
        alive = tmp->next;
        free(tmp);
        tmp = alive;
        printf("%dȸ free�Ǿ����ϴ�.\n",count);
        count++;
    }
}

void getNodeLength(Node *list)
{
    int count = -1; //head�� �������� �ʴ´�!
    Node *tmp = list;
    while(tmp != NULL)
    {
        tmp = tmp->next;
        count++;
    }
    printf("list�� ���̴� %d�Դϴ�.\n",count);
}

void insert(Node *list, int order, int data)
{
//NewNode�� data�ֱ� �� malloc �ϱ�!
//head�� ������ ��ġ�� �����Ѵ�.
    Node *tmp = list;
    Node *NewNode = malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->next = NULL;

    for(int i = 1; i<order; i++)
    {
        tmp = tmp->next;
    }
    NewNode->next = tmp->next;
    tmp->next = NewNode;
}

void swapNodeData_specific(Node *list, int order1, int order2)
{
    int data1;
    int data2;
    Node *tmp = list;
    for(int i = 0; i<order1; i++)
    {
        tmp = tmp->next;
    }
    data1 = tmp->data;

    tmp = list;
    for(int i = 0; i<order2; i++)
    {
        tmp = tmp->next;
    }
    data2 = tmp->data;
    tmp->data = data1;

    tmp = list;
    for(int i = 0; i<order1; i++)
    {
        tmp = tmp->next;
    }
    tmp->data = data2;
}
//[EXPERIMENT]_struct.c ����, swapNodeData_specific, insert, getNodeLength�Լ� ����, showList �Լ� ����, Test�κ� ����