#include <stdio.h> 
#include <stdlib.h>

int Is_empty();
int Is_full();
void Enqueue(int arr[], int item);
void Dequeue(int arr[]);
void Print_arr(int arr[]);

int front = -1;
int rear = -1;
const int MAX = 10;
// front = 현재 queue에 들어온 값중 가장 먼저 들어온 값의 바로 앞칸을 지정함(공백칸) rear = 현재 queue에 들어온 값중
// 가장 나중에 들어온(최신) 값이 있는 칸을 지정함 순환queue는 고정queue에 비해 메모리 낭비가 적다. 최초 front와 rear가
// -1값을 지니며 이후 Enqueue와 Dequeue에 의해 0~MAX-1사이의 값을 갖게된다. 주의할점은 front가 가르키는 값은 항상
// 비어있다 즉 메모리 사용량은 MAx - 1이 된다.

int main() {
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int item;

    while (1) {
        int choice = 0;
        printf("\n");
        printf("circular queue test\n");
        printf("1. Enqueue 2. Dequeue 3. print arr 4. print front and rear 5. exit\n");
        scanf("%d", & choice);

        switch (choice) {
            case 1:
                    printf("input number : ");
                    scanf("%d", & item);
                    printf("\n");
                    Enqueue(arr, item);
                    break;

            case 2:
                    Dequeue(arr);
                    break;
            
            case 3:
                Print_arr(arr);
                break;
            
            case 4:
                printf("front : %d, rear : %d\n",front, rear);
                break;
            
            case 5:
                exit(1);
                
                
        }
    }

    return 0;
}

int Is_empty() {
    if (front == rear) 
        return 1;
    
else 
        return 0;
    }

int Is_full() {
    if (((front - 1) == rear) || ((rear - front) >= (MAX - 1))) //코드를 변형하여 if((rear + 1) % (n+1) == front)로 바꿀 수 있다.
        return 1;
    
else 
        return 0;
    }

void Enqueue(int arr[], int item) {
    if (Is_full() == 1) {
        printf("순환된 queue가 꽉 찼습니다.\n");
        return;
    }
    if (rear == (MAX - 1)) 
        rear = -1;
    rear = rear + 1;
    arr[rear] = item;
    printf("숫자 %d가 %d번째 칸에 Enqueue되었습니다.\n", arr[rear], rear);
}

void Dequeue(int arr[]) {
    if (Is_empty() == 1) {
        printf("순환된 queue가 비었습니다.\n");
        return;
    }
    if (front == (MAX - 1)) 
        front = -1;
    front = front + 1;
    int item = arr[front];
    arr[front] = -1;
    printf("숫자 %d가 %d번째 칸으로 부터 Dequeue되었습니다.\n", item, front);
}

void Print_arr(int arr[]) {
    for (int i = 0; i < MAX; i++) {
        printf("숫자: %d, 칸: %d\n", arr[i], i);
    }
    printf("\n");
}
