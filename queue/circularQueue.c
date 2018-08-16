# include <stdio.h>
# include <stdlib.h>

# define MAX 10

struct queue{
    int arr[MAX];
    int front, rear, size;
};

void initqueue(struct queue *);
void addq(struct queue*, int item);
int delq(struct queue*);
void display(struct queue*);


int main(void){
    struct queue q;
    initqueue(&q);
    
    addq(&q,14 );
    addq(&q,22 );
    addq(&q,13 );
    addq(&q,-6 );
    addq(&q, 25);
    
    printf("Elements in circular queue.\n");
    display(&q);
    int i;
    i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
    i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
    printf("Elements in circular queue after deletion:\n");
    display(&q);
    
    addq(&q, 21);
    addq(&q, 17);
    addq(&q, 18);
    addq(&q, 9);
    addq(&q, 20);
    
    printf("Elements in the circular queue after additon:\n");
    display(&q);
    
    addq(&q, 32);
    addq(&q, 2);
    printf("Elements in the circular queue after additon:\n");
    display(&q);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
     i = delq(&q);
    if( i != NULL)
        printf("Item deleted: %d\n",i);
    
}

void initqueue(struct queue* q){
    q->front = -1;
    q->rear = 0;
    q->size = 0;
}

void addq(struct queue *q, int item){
    if( q->size == MAX-1 ){
        printf("Queue is full.\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    
    q->arr[ q->rear ] = item;
    q->rear = ( q->rear + 1)%MAX;
    q->size++;
}


int delq(struct queue *q){
    if( q->front == q->rear || q->front == -1){
        printf("Queue is empty.\n");
        return NULL;
    }
    int item = q->arr[q->front];
    q->front = (q->front + 1)%MAX;
    q->size--;
    return item;
}

void display(struct queue *q){
    int i = q->front;
    while( i != q->rear){
        
        printf( "%d ", q->arr[i] );
        i = (i+1)%MAX;
    }
    printf("\n");
}

