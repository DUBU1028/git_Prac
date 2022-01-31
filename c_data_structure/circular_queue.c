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
// front = ���� queue�� ���� ���� ���� ���� ���� ���� �ٷ� ��ĭ�� ������(����ĭ) rear = ���� queue�� ���� ����
// ���� ���߿� ����(�ֽ�) ���� �ִ� ĭ�� ������ ��ȯqueue�� ����queue�� ���� �޸� ���� ����. ���� front�� rear��
// -1���� ���ϸ� ���� Enqueue�� Dequeue�� ���� 0~MAX-1������ ���� ���Եȴ�. ���������� front�� ����Ű�� ���� �׻�
// ����ִ� �� �޸� ��뷮�� MAx - 1�� �ȴ�.

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
    if (((front - 1) == rear) || ((rear - front) >= (MAX - 1))) //�ڵ带 �����Ͽ� if((rear + 1) % (n+1) == front)�� �ٲ� �� �ִ�.
        return 1;
    
else 
        return 0;
    }

void Enqueue(int arr[], int item) {
    if (Is_full() == 1) {
        printf("��ȯ�� queue�� �� á���ϴ�.\n");
        return;
    }
    if (rear == (MAX - 1)) 
        rear = -1;
    rear = rear + 1;
    arr[rear] = item;
    printf("���� %d�� %d��° ĭ�� Enqueue�Ǿ����ϴ�.\n", arr[rear], rear);
}

void Dequeue(int arr[]) {
    if (Is_empty() == 1) {
        printf("��ȯ�� queue�� ������ϴ�.\n");
        return;
    }
    if (front == (MAX - 1)) 
        front = -1;
    front = front + 1;
    int item = arr[front];
    arr[front] = -1;
    printf("���� %d�� %d��° ĭ���� ���� Dequeue�Ǿ����ϴ�.\n", item, front);
}

void Print_arr(int arr[]) {
    for (int i = 0; i < MAX; i++) {
        printf("����: %d, ĭ: %d\n", arr[i], i);
    }
    printf("\n");
}
