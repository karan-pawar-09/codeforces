#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
}; 

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void push(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)% queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
 

int pop(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)% queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
int front(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
int rear(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
struct Queue* queue;

void Print() {
    while (!isEmpty(queue))
    {   
        printf("%d ",front(queue));
     
        int j= pop(queue);
    }
}

int main() {  
    int n;
    scanf("%d",&n);
    queue=createQueue(n+7);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        push(queue,a);
    }
    int arr[n];
    for(int i=0;i<n;i++) {
        arr[i]=pop(queue);
    }
    
    int k;
    scanf("%d",&k);
    for(int i=0;i<k/2;i++) swap(&arr[i],&arr[k-1-i]);
    for(int i=0;i<n;i++) {
        push(queue,arr[i]);
    }
    
    Print(queue);
}