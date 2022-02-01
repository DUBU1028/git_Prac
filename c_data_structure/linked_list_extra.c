#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    struct Node *next;
    int data;
}Node;

void append(Node *list, int data);
void showList(Node *list);
void deleteList(Node *list);


int main()
{
    int input1;
    int input2;
    int input3;
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    printf("1�� node�� ���� data�� �Է��� �ּ���: ");
    scanf("%d",&input1);
    printf("2�� node�� ���� data�� �Է��� �ּ���: ");
    scanf("%d",&input2);
    printf("3�� node�� ���� data�� �Է��� �ּ���: ");
    scanf("%d",&input3);
    append(head, input1);
    append(head, input2);
    append(head, input3);
    showList(head);
    deleteList(head);
    //showList(head);

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
    int count=0;
    Node *tmp = list;
    while(tmp != NULL)
    {
        printf("%d�� node�� data: %d\n",count, tmp->data);
        tmp = tmp->next;
        count++;
    }
}

void deleteList(Node *list)
{
    Node *tmp = list;
    Node *alive;
    int count=1;
    while(tmp != NULL)
    {
        alive = tmp->next;
        free(tmp);
        tmp = alive;
        printf("%dȸ free�Ǿ����ϴ�.\n",count);
        count++;

    }
}
//typedef struct����� struct ������ ������: typedef struct������ ��Ī�� �����Ͽ� main�κп��� struct�� ����� �ʿ� ���� ��Ī���� �ٷ� ���ο� ����ü�� ��������
//�ݸ� �Ϲ����� struct������ ��Ī�� ����� �� ����

// typedef struct ttt{
//     int data;
// }ta;

// struct sss{

//     int memory;
// }sa;

// int main()
// {
//     struct ttt t1;
//     struct sss s1;
//     ta t2;
//     sa s2;
    
//     return 0;
// }