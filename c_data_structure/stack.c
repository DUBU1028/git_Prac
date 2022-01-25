#include <stdio.h>

int Is_empty(int top);
int Is_full(int top);
int push(int arr[], int top, int item);
int pop(int arr[], int top);
void Print_arr(int arr[]);

int main(void)
{
	//testcase - 배열을 이용한 stack 구성하기
	int arr[10] = {0};
	int top = -1;
	top = push(arr, top, 10);
	top = push(arr, top, 15);
	top = push(arr, top, 30);
	top = pop(arr, top);
	top = pop(arr, top);
	top = pop(arr, top);
	top = pop(arr, top);
	top = push(arr, top, 10);
	top = push(arr, top, 20);
	top = push(arr, top, 30);
	top = push(arr, top, 40);
	top = push(arr, top, 50);
	top = push(arr, top, 60);
	top = push(arr, top, 70);
	top = push(arr, top, 80);
	top = push(arr, top, 90);
	top = push(arr, top, 100);
	top = push(arr, top, 200);
	top = pop(arr, top);
	top = pop(arr, top);
	top = pop(arr, top);
	top = pop(arr, top);
	top = pop(arr, top);
	top = pop(arr, top);
	top = pop(arr, top);
	top = pop(arr, top);
	Print_arr(arr);
	printf("This line is edited in git bash\n");
	printf("This line is edited in git bash - 2\n");

	return 0;
}

int Is_empty(int top)
{
	if(top == -1)
	return 1;

	else
	return 0;
}

int Is_full(int top)
{
	if(top == 9)
	return 1;

	else
	return 0;
}

int push(int arr[], int top, int item)
{
	if(Is_full(top) == 1)
	{
		printf("stack이 꽉 찼습니다.\n");
		return top;
	}
	int tmp = top;
	tmp = tmp+1;
	arr[tmp] = item;
	printf("숫자 %d가 %d번째 칸에 push되었습니다.\n",item, tmp);
	return tmp;
}

int pop(int arr[], int top)
{
	if(Is_empty(top) == 1)
	{
		printf("stack이 비었습니다\n");
		return top;
	}
	
	int tmp = top;
	int item = arr[tmp];
	arr[tmp] = NULL;
	printf("숫자 %d가 %d번째 칸으로 부터 pop되었습니다.\n",item, tmp);
	tmp = tmp-1;
	return tmp;
}

void Print_arr(int arr[])
{
	for (int i = 0; i < 10 ; i++)
	{
		printf("숫자: %d, 칸: %d\n",arr[i],i);
	}
}
