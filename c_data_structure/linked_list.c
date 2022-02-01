#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *Pointer;
    int data;
};


int main()
{
    struct Node *head = malloc(sizeof(struct Node));
    
    return 0;
}