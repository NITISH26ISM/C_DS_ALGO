# include <stdio.h>
# include <stdlib.h>

#define MAX 13

typedef struct deque{
    int arr[MAX];
    int front, rear, size;
}deque;

void initdeque(deque*);
void pushFront(deque*, int);
void pushRear(deque*, int);
int popFront(deque*);
int popRear(deque*);
void display(deque*);


int main(void){
    deque q;
    
    initdeque(&q);
    
    pushFront(&q,17);
    pushRear(&q,10);
    pushFront(&q,8);
    pushRear(&q,-9);
    pushFront(&q,13);
    pushRear(&q,28);
    pushFront(&q,14);
    pushRear(&q,5);
    pushFront(&q,25);
    pushRear(&q,6);
    pushFront(&q,21);
    pushRear(&q,11);
    
    printf("Elements in a dequeue:\n");
    display(&q);
    
    int i;
    i = popFront(&q);
    if( i != NULL)
        printf("Item poped: %d\n",i);
    
    i = popFront(&q);
    if( i != NULL)
        printf("Item poped: %d\n",i);
    
    i = popFront(&q);
    if( i != NULL)
        printf("Item poped: %d\n",i);
    
    i = popFront(&q);
    if( i != NULL)
        printf("Item poped: %d\n",i);
    
    printf("Elements in a dequeue after deletion:\n");
    display(&q);
    
    
    pushRear(&q,16);
    pushRear(&q, 7);
    
    printf("Elements in a deque after addition:\n");
    display(&q);
    
    i = popRear(&q);
    if( i != NULL)
        printf("Item poped: %d\n",i);
    
    i = popRear(&q);
    if( i != NULL)
        printf("Item poped: %d\n",i);
    
    printf("Elements in a dequeue after deletion:\n");
    display(&q);
    
}

void initdeque(deque *q){
    q->front = -1;
    q->rear = 0;
    q->size = 0;
}

void pushFront(deque *q, int item){
    if( q->size == MAX - 1)
    {
        printf("DeQueue is full.\n");
        return;
    }
    
    q->size++;
    
    if( q->front == q->rear){
        q->arr[q->front] = item;
        q->rear = (q->rear + 1)%MAX;
        return ;
    }
    if(q->front == -1){
        q->front = 0;
        q->arr[q->front] = item;
        q->rear = (q->rear+1)%MAX;
        return ;
    }
    
    q->front = (q->front - 1 + MAX)%MAX;
    q->arr[q->front] = item;
    
}

void pushRear(deque *q, int item){
    if( q->size == MAX - 1)
    {
        printf("DeQueue is full.\n");
        return;
    }
    
    q->size++;
    
    if(q->front == -1){
        q->front = 0;
        q->arr[q->front] = item;
        q->rear = (q->rear+1)%MAX;
        return;
    }
    
    q->arr[q->rear] = item;
    q->rear = (q->rear + 1)%MAX;
}


int popFront(deque *q){
    if(q->front == -1 || q->front == q->rear){
        printf("DeQue is empty.\n");
        return NULL;
    }
    q->size--;
    int item = q->arr[q->front];
    q->front = (q->front+1)%MAX;
    return item;
}

int popRear(deque *q){
    if(q->front == -1 || q->front == q->rear){
        printf("DeQue is empty.\n");
        return NULL;
    }
    q->size--;
    
    int item = q->arr[ q->rear - 1 ];
    q->rear = (q->rear - 1 + MAX )%MAX;
    return item;
    
}

void display(deque *q){
    int i = q->front;
    if(q->front == -1 || q->front == q->rear){
        printf("DeQue is empty.\n");
        return;
    }
    
    while(i != q->rear){
        printf("%d ", q->arr[i]);
        i = (i+1)%MAX;
    }
    printf("\n");
    
}

