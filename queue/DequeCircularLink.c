# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct queue{
    node *rear;
}queue;


void initqueue( queue* );
void push( queue* , int);
int pop( queue* );
void display(queue*);

int main(){
    queue q;
    initqueue(&q);
    
    push(&q, 12);
    push(&q, 14);
    push(&q, 5);
    push(&q, -2);
    push(&q, 18);
    
    printf("queue after addition:\n");
    display(&q);
    
    pop(&q);
    pop(&q);
    printf("queue after popping:\n");
    display(&q);
    
    return 0;
}

void initqueue( queue *q ){
    q->rear = NULL;
}

void push(queue *q, int item){
    node* temp = (node*)malloc(sizeof(node));
    
    if(temp == NULL)
    {
        printf("the Queue is full\n");
        return ;
    }
    
    temp->data = item;
    
    if(q->rear == NULL){
        temp->next = temp;
        q->rear = temp;
        return;
    }
    
    node *t = q->rear->next;
    q->rear->next = temp;
    temp->next = t;
    
    q->rear = q->rear->next;
}

int pop(queue *q){
    if(q->rear == NULL){
        printf("Queue is empty\n");
        return NULL;
    }
    
}

















