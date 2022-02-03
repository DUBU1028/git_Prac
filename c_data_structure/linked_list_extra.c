#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    struct Node *next;
    int data;
}Node;

void append(Node *list, int data); //list의 맨마지막 node뒤에 새로운 node 생성
void showList(Node *list);//현재 list 내부 node들의 data를 나열(head포함)
void deleteList(Node *list);//list 내부 node들을 삭제하며 메모리 할당을 free시킴
void getNodeLength(Node *list);// list에 node 수를 출력(head 제외)
void insert(Node *list, int order, int data);// list에 특정 순서에 새로운 node를 추가(head를 제외한 node순번)
void swapNodeData_specific(Node *list, int order1, int order2);// list내부 특정 두 node의 data를 바꿈(head를 제외한 node순번)


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
        printf("숫자를 입력하십시오: ");
        scanf("%d",&choice);

        switch(choice){

            case 1 :
                printf("추가할 숫자를 입력하십시오: ");
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
                printf("추가할 위치와 숫자를 입력하십시오: ");
                scanf("%d %d",&order1, &data);
                insert(head, order1, data);
                printf("\n");
                break;
            
            case 5:
                printf("변경할 두 Node의 위치를 입력하십시오: ");
                scanf("%d %d",&order1, &order2);
                swapNodeData_specific(head, order1, order2);
                printf("\n");
                break;

            case 6 :
                deleteList(head);
                return 0;
            
            default :
                printf("유효한 숫자를 입력해주십시오\n\n");
            
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
    printf("head의 data: %d\n",tmp->data);
    tmp= tmp->next;
    while(tmp != NULL)
    {
        printf("%d번 node의 data: %d\n",count, tmp->data);
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
        printf("%d회 free되었습니다.\n",count);
        count++;
    }
}

void getNodeLength(Node *list)
{
    int count = -1; //head는 포함하지 않는다!
    Node *tmp = list;
    while(tmp != NULL)
    {
        tmp = tmp->next;
        count++;
    }
    printf("list의 길이는 %d입니다.\n",count);
}

void insert(Node *list, int order, int data)
{
//NewNode에 data넣기 및 malloc 하기!
//head를 제외한 위치에 삽입한다.
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
//[EXPERIMENT]_struct.c 생성, swapNodeData_specific, insert, getNodeLength함수 생성, showList 함수 수정, Test부분 수정