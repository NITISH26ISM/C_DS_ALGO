# include <stdio.h>

# define MAX 100

struct stack{
    int arr[MAX];
    int top;
};

void initstack(struct stack *);
void push(struct stack *, int item );
int pop(struct stack *);
int isEmpty(struct stack *);
int top(struct stack*);

int main(){
    struct stack s;
    //int i = 0;
    
    int price[] = { 10, 8, 2 , 4, 3 , 5, 9};
    int si = sizeof(price) / sizeof(int);
    int span[si];
    
    initstack(&s);
    
    for(int i = 0; i < si; i++){
        
        while( !isEmpty(&s) && price[top(&s)] < price[i] ){
            pop(&s);
        }
        
        span[i] = i - top(&s);
        push(&s, i);
    }
    
    for(int i = 0; i < si; i++)
        printf( "%d, ", span[i] );
}

void initstack( struct stack *p){
    p->top = -1;
}

void push(struct stack *p, int item){
    if( p->top == MAX - 1){
        printf("Stack is full\n");
        return ;
    }
    else{
        p->top++;
        p->arr[p->top] = item;
    }
}

int pop(struct stack *p){
    if( p->top == -1){
        printf("Stack is empty.\n");
        return -1;
    }
    else{
        int data = p->arr[p->top];
        p->top--;
        return data;
    }
}


int isEmpty(struct stack *p){
    return (p->top == -1);
}


int top(struct stack *p)
{
    if(p->top == -1){
        printf("Stack is empty.\n");
        return -1;
    }
    return p->arr[p->top];
}











