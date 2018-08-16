# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct queue{
    struct node *front;
    struct node *rear;
};

void initQueue(struct queue*);
void addq(struct queue*, int );
int delq(struct queue*);
void delqueue(struct queue*);

int main(){
    struct queue a;
    int i;
    initQueue(&a);
    
    addq(&a, 11);
     addq(&a, -8);
      addq(&a, 23);
       addq(&a, 19);
       // addq(&a, 15);
        
        i = delq(&a);
        if( i != NULL)
            printf("Item extracted: %d\n",i);
        
        i = delq(&a);
        if( i != NULL)
            printf("Item extracted: %d\n",i);
        
        i = delq(&a);
        if( i != NULL)
            printf("Item extracted: %d\n",i);
        
        i = delq(&a);
        if( i != NULL)
            printf("Item extracted: %d\n",i);
        
        i = delq(&a);
        if( i != NULL)
            printf("Item extracted: %d\n",i);
        
        delqueue(&a);
        return 0;
        
}

void initQueue(struct queue *q)
{
    q->front = q->rear = NULL;
}

void addq( struct queue *q, int item ){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    
    if(temp == NULL){
        printf("Queue is full\n");
        return;
    }
    
    temp->data = item;
    temp->next = NULL;
    
    if(q->front == NULL){
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
    
}

int delq(struct queue *q){
    struct node *temp;
    int item;

    if(q->front == NULL){
        printf("Queue is empty.\n");
        return NULL;
    }
    item = q->front->data;
    temp = q->front;
    q->front = q->front->next;
    free(temp);
    return item;
}

void delqueue(struct queue *q)
{
    struct node *temp;
    if(q->front == NULL)
        return ;
    
    while( q->front != NULL){
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    
    
}
