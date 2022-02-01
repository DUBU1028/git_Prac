#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *Pointer;
    int data;
};

//linked_list 하나씩 만들어서 사용해보기

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

    printf("node1의 data 참조하기\n");
    printf("1. head로 참조: %d, 2. node1으로 참조: %d\n\n",head->Pointer->data, node1->data);
    printf("node2의 data 참조하기\n");
    printf("1. head로 참조: %d, 2. node1으로 참조: %d, 3. node2로 참조: %d\n\n",head->Pointer->Pointer->data, node1->Pointer->data, node2->data);
    printf("node3의 data 참조하기\n");
    printf("1. head로 참조: %d, 2. node1으로 참조: %d, 3. node2로 참조: %d, 4. node3으로 참조: %d\n\n",head->Pointer->Pointer->Pointer->data, node1->Pointer->Pointer->data, node2->Pointer->data, node3->data);

    struct Node *test = head->Pointer;//반복문을 사용하기 위한 새로운 포인터 변수?

    while(test != NULL)//연결된 모든 node의 data를 순서대로 출력하는 반복문
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