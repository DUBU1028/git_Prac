#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *Pointer;
    int data;
};
//array list�� �̿��� node ���� �ǽ� - *�� �̿��Ͽ� ���ʿ� ����Ǿ��ִ� node�� data �� pointer�� ������

int main()
{
    struct Node abc[3];
    abc[0].data = 0;
    abc[0].Pointer = &abc[1];

    abc[1].data = 10;
    abc[1].Pointer = &abc[2];

	 abc[2].data = 20;
	 abc[2].Pointer = NULL;

	printf("0��ĭ�� �ּ�: %p, 0��ĭ�� data��: %d, 0��ĭ�� pointer�� ����Ű�� �ּ�: %p\n",&abc[0], abc[0].data, abc[0].Pointer);
	printf("1��ĭ�� �ּ�: %p, 1��ĭ�� data��: %d, 1��ĭ�� pointer�� ����Ű�� �ּ�: %p\n",&abc[1], abc[1].data, abc[1].Pointer);
    printf("2��ĭ�� �ּ�: %p, 2��ĭ�� data��: %d, 2��ĭ�� pointer�� ����Ű�� �ּ�: %p\n",&abc[2], abc[2].data, abc[2].Pointer);
	printf("�迭�� �ּ�: %p\n",abc);
    printf("%d\n",(*abc[0].Pointer).data);
    printf("%d\n",(*(*abc[0].Pointer).Pointer).data);
    printf("%p\n",(*abc[0].Pointer).Pointer);
    printf("%p\n",(*(*abc[0].Pointer).Pointer).Pointer);
    return 0;
}