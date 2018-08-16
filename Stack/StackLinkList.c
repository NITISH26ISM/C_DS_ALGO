# include <stdio.h>
# include <stdlib.h>


struct node{
    int data;
    struct node *link;
};

void push(struct node**, int );
int pop(struct node**);
void delstack(struct node**);

int main(){
    struct node *s = NULL;
    int i;
    while(1){
        push( &s, 14 );
        push( &s, -3 );
        push( &s, 18 );
        push( &s, 29 );
    }
    i = pop(&s);
    if( i != NULL)
        printf("Item poped: %d \n", i);
        i = pop(&s);
    if(i != NULL)
        printf("Item popped: %d\n",i);
        i = pop(&s);
    if(i != NULL)
        printf("Item popped: %d\n",i);
        i = pop(&s);
    if(i != NULL)
        printf("Item popped: %d\n",i);
        i = pop(&s);
    if(i != NULL)
        printf("Item popped: %d\n",i);
        i = pop(&s);
    if(i != NULL)
        printf("Item popped: %d\n",i);
    
    delstack(&s);
    return 0;
}


void push( struct node** top, int item ){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    
    if(temp == NULL){
        printf("Stack is full\n");
    }
    temp->data = item;
    temp->link = *top;
    *top = temp;
}

int pop(struct node **top){
    struct node *temp;
    int item;
    if(*top == NULL){
        printf("Stack is empty\n");
        return NULL;
    }
    temp = *top;
    item = temp->data;
    *top = (*top)->link;
    free(temp);
    return item;
}

void delstack(struct node **top){
    struct node *temp;
    if(*top == NULL)
        return ;
    
    while(*top != NULL){
        temp = *top;
        *top = (*top)->link;
        free(temp);
    }
}




