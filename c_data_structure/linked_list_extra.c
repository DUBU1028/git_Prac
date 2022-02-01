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
    printf("1번 node에 넣을 data를 입력해 주세요: ");
    scanf("%d",&input1);
    printf("2번 node에 넣을 data를 입력해 주세요: ");
    scanf("%d",&input2);
    printf("3번 node에 넣을 data를 입력해 주세요: ");
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
        printf("%d번 node의 data: %d\n",count, tmp->data);
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
        printf("%d회 free되었습니다.\n",count);
        count++;

    }
}
//typedef struct선언과 struct 선언의 차이점: typedef struct선언은 별칭을 지정하여 main부분에서 struct를 사용할 필요 없이 별칭으로 바로 새로운 구조체를 생성가능
//반면 일반적인 struct선언은 별칭을 사용할 수 없음

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