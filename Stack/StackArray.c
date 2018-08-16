# include <stdio.h>

#define MAX 4

struct stack{
    int arr[MAX];
    int top;
};

void initstack( struct stack* );
void push(struct stack*, int item);
int pop(struct stack*);

int main(){
    struct stack s;
    int i;
    initstack(&s);
    
    push( &s, 11 );
    push( &s, 23 );
    push( &s, -8 );
    push( &s, 16 );
    push( &s, 27 );
    
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
    
    
    return 0;
    
}


void initstack(struct stack *s){
    s->top = -1;
}


void push(struct stack *s , int item){
    if(s->top == MAX-1 ){
        printf("Stack is full.\n");
        return ;
    }
    
    s->top++;
    s->arr[s->top] = item;
}

int pop(struct stack *s){
    if(s->top == -1)
    {
        printf("Stack is empty!");
        return NULL;
    }
    int data = s->arr[s->top];
    s->top--;
    return data;
}











