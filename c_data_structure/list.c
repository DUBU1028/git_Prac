#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *Pointer;
    int data;
};
//array list를 이용한 node 연결 실습 - *를 이용하여 뒤쪽에 연결되어있는 node의 data 및 pointer를 참조함

int main()
{
    struct Node abc[3];
    abc[0].data = 0;
    abc[0].Pointer = &abc[1];

    abc[1].data = 10;
    abc[1].Pointer = &abc[2];

	 abc[2].data = 20;
	 abc[2].Pointer = NULL;

	printf("0번칸의 주소: %p, 0번칸의 data값: %d, 0번칸의 pointer가 가르키는 주소: %p\n",&abc[0], abc[0].data, abc[0].Pointer);
	printf("1번칸의 주소: %p, 1번칸의 data값: %d, 1번칸의 pointer가 가르키는 주소: %p\n",&abc[1], abc[1].data, abc[1].Pointer);
    printf("2번칸의 주소: %p, 2번칸의 data값: %d, 2번칸의 pointer가 가르키는 주소: %p\n",&abc[2], abc[2].data, abc[2].Pointer);
	printf("배열의 주소: %p\n",abc);
    printf("%d\n",(*abc[0].Pointer).data);
    printf("%d\n",(*(*abc[0].Pointer).Pointer).data);
    printf("%p\n",(*abc[0].Pointer).Pointer);
    printf("%p\n",(*(*abc[0].Pointer).Pointer).Pointer);
    return 0;
}