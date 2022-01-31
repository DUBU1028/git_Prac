#include <stdio.h>
int Is_empty();
int Is_full();
void Enqueue(int arr[], int item);
void Dequeue(int arr[]);
void Print_arr(int arr[]);

int front = -1;
int rear = -1;
//front = 현재 queue에 들어온 값중 가장 먼저 들어온 값의 바로 앞칸을 지정함(공백칸)
//rear = 현재 queue에 들어온 값중 가장 나중에 들어온(최신) 값이 있는 칸을 지정함


//queue의 크기가 고정되어 있으며 순환되지 않는 queue를 구상함
int main()
{
    int arr[10] = {0};
    Enqueue(arr, 10);
    Enqueue(arr, 20);
    Enqueue(arr, 30);
    Enqueue(arr, 40);
    Enqueue(arr, 50);
    Enqueue(arr, 60);
    Dequeue(arr);
    Dequeue(arr);
    Dequeue(arr);
    Print_arr(arr);
    return 0;
}

int Is_empty()
{
    if(front == rear)
    return 1;

    else
    return 0;
}

//queue의 크기가 고정되어 있으므로(순환하는 queue가 아니므로) rear의 값이 queue의 크기 - 1 값과 같다면 full이다.
int Is_full()
{
    if(rear == 9)
    return 1;

    else
    return 0;
}

void Enqueue(int arr[], int item)
{
    if(Is_full() == 1)
    {
        printf("고정된 queue가 꽉 찼습니다.\n");
        return ;
    }
    rear = rear + 1;
    arr[rear] = item;
    printf("숫자 %d가 %d번째 칸에 Enqueue되었습니다.\n",arr[rear], rear);
}

void Dequeue(int arr[])
{
    if(Is_empty()==1)
    {
        printf("고정된 queue가 비었습니다.\n");
        return ;
    }
    front = front + 1;
    int item = arr[front];
    arr[front] = NULL;
    printf("숫자 %d가 %d번째 칸으로 부터 Dequeue되었습니다.\n",item, front);
}

void Print_arr(int arr[])
{
    for (int i = 0; i < 10 ; i++)
	{
		printf("숫자: %d, 칸: %d\n",arr[i],i);
	}
}
