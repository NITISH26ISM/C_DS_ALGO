# include <stdio.h>
# include <string.h>

# define MAX 50

struct postfix{
    char stack[MAX][MAX], target[MAX];
    char temp1[2], temp2[2];
    char str1[MAX], str2[MAX], str3[MAX];
    int i,top;
};

void initpostfix(struct postfix* );
void setexpr(struct postfix*, char * );
void push(struct postfix*, char );
void pop(struct postfix*, char* );
void convert( struct postfix* );
void show( struct postfix );

int main(){
    struct postfix q;
    char expr[MAX];
    
    initpostfix(&q);
    
    printf("Enter an expression in postfix form: \n");
    gets(expr);
     
    setexpr(&q,expr);
    
    convert(&q);
    
    printf("The Prefix expression is:\n");
    
    show(q);
    return 0;
}

void initpostfix(struct postfix *p)
{
    p->i = 0;
    p->top = -1;
    strcpy(p->target, "");
}

void setexpr( struct postfix *p, char *c)
{
    strcpy(p->target, c);
}

void push(struct postfix *p, char *str)
{
    if( p->top == MAX-1){
        printf("Stack is full\n");
    }
    else{
        p->top++;
        strcpy(p->stack[p->top], str);
    }
}

void pop(struct postfix *p, char *a)
{
    if(p->top == -1){
        printf("Stack is empty.\n");
        return NULL;
    }
    else{
        strcpy(a, p->stack[p->top] );
        p->top--;
    }
}

void convert(struct postfix *p){
    while( p->target[p->i] != '\0' ){
        if( p->target[p->i] == ' ' )
            p->i++;
        
        if( p->target[p->i] == '%' || p->target[p->i] == '*' || p->target[p->i] == '-' || p->target[p->i] == '+' || p->target[p->s] == '/'|| p->target[p->s] == '$' )
        {
            pop(p, p->str2);
            pop(p, p->str3);
            p->
        }
    }
}


void show(struct postfix p){
    char *temp = p.stack[0];
    while(*temp){
        printf("%c", *temp );
        temp++;
    }
}








