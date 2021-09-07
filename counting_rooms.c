#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int visited[107][107];
int arr[107][107];
int n,m;

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
 
// int front(struct Queue* queue) {
//     if (isEmpty(queue))
//         return INT_MIN;
//     return queue->array[queue->front];
// }
 
// int rear(struct Queue* queue) {
//     if (isEmpty(queue))
//         return INT_MIN;
//     return queue->array[queue->rear];
// }

struct Queue* queue; 
struct Queue* queue1;

int isValid(int a,int b) {
    if(a<0||a>n-1||b<0||b>m-1) {
        return 0;
    }
    if(visited[a][b]||arr[a][b]==0) {
        return 0;
    }
    return 1;
}
void bfs(int i, int j) {
    int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
    int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };


    push(queue,i);
    push(queue1,j);
    visited[i][j]=1;
    while (queue->size!=0) {
        int x=pop(queue1);
        int y=pop(queue);
        for (int k = 0; k < 8; k++) {          
            if (isValid( x + row[k], y + col[k])) {
                visited[x + row[k]][y + col[k]] = 1;
                push(queue,x + row[k]);
                push(queue1,y + col[k]);
            }
        }
    }
}

int main() {   
    queue= createQueue(107);
    queue1=createQueue(107);
    // scanf("%d %d",&n,&m);  
    n=10;
    m=10;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
   
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]&&!visited[i][j]) {                
                ans++;
                bfs(i,j);
            }
        }
    }
    printf("%d\n",ans);
}

