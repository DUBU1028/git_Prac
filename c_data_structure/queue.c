#include <stdio.h>
int Is_empty();
int Is_full();
void push(int arr[], int item);
void pop(int arr[]);
void Print_arr(int arr[]);

int top = -1;
int bottom = -1;
//top = 현재 queue에 들어온 값중 가장 먼저 들어온 값의 바로 앞칸을 지정함(공백칸)
//bottom = 현재 queue에 들어온 값중 가장 나중에 들어온(최신) 값이 있는 칸을 지정함


//queue의 크기가 고정되어 있으며 순환되지 않는 queue를 구상함
int main()
{
    int arr[10] = {0};
    push(arr, 10);
    push(arr, 20);
    push(arr, 30);
    push(arr, 40);
    push(arr, 50);
    push(arr, 60);
    pop(arr);
    pop(arr);
    pop(arr);
    Print_arr(arr);
    return 0;
}

int Is_empty()
{
    if(top == bottom)
    return 1;

    else
    return 0;
}

//queue의 크기가 고정되어 있으므로(순환하는 queue가 아니므로) bottom의 값이 queue의 크기 - 1 값과 같다면 full이다.
int Is_full()
{
    if(bottom == 9)
    return 1;

    else
    return 0;
}

void push(int arr[], int item)
{
    if(Is_full() == 1)
    {
        printf("고정된 queue가 꽉 찼습니다.\n");
        return ;
    }
    bottom = bottom + 1;
    arr[bottom] = item;
    printf("숫자 %d가 %d번째 칸에 push되었습니다.\n",arr[bottom], bottom);
}

void pop(int arr[])
{
    if(Is_empty()==1)
    {
        printf("고정된 queue가 비었습니다.\n");
        return ;
    }
    top = top + 1;
    int item = arr[top];
    arr[top] = NULL;
    printf("숫자 %d가 %d번째 칸으로 부터 pop되었습니다.\n",item, top);

}

void Print_arr(int arr[])
{
    for (int i = 0; i < 10 ; i++)
	{
		printf("숫자: %d, 칸: %d\n",arr[i],i);
	}
}
