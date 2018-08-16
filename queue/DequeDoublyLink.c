# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node ;

typedef struct deque{
    node *header, *trailer;
    int size;
}deque;

void initdeque( deque* );
void pushFront( deque*, int );
void pushRear( deque*, int );
int popFront( deque* );
int popRear( deque* );
void display( deque* );

int main(){
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

void initdeque(deque* q){
    q->header = (node*)malloc(sizeof(node));
    q->trailer = (node*)malloc(sizeof(node));

    q->header->prev = NULL;
    q->trailer->next = NULL;

    q->header->next = q->trailer;
    q->trailer->prev = q->header;
    q->size = 0;
}

void pushFront( deque *q, int item )
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = item;
    
    node *t = q->header->next;
    temp->next = t;
    temp->prev = q->header;
    q->header->next = temp;
    t->prev = temp;
}

void pushRear(deque *q, int item){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = item;
    
    node* t = q->trailer->prev;
    temp->next = q->trailer;
    temp->prev = t;
    q->trailer->prev = temp;
    t->next = temp;
    
}

int popFront(deque *q){
    int data;
    node *temp = q->header->next;
    data = temp->data;
    q->header->next = temp->next;
    temp->next->prev = q->header;
    free(temp);
    return data;
}

int popRear(deque *q){
    int data;
    node *temp = q->trailer->prev;
    data = temp->data;
    q->trailer->prev = temp->prev;
    temp->prev->next = q->trailer;
    free(temp);
    return data;
}


void display( deque *q ){
    node *temp = q->header->next;
    while( temp != q->trailer){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}



