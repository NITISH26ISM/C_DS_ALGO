# include <stdio.h>
# include <string.h>
# include <ctype.h>

# define MAX 50


struct infix{
    char target[MAX];
    char stack[MAX];
    char *s, *t;
    int top, l;
};

void initinfix(struct infix*);
void setexpr(struct infix*, char *);
void push(struct infix*, char);
char pop(struct infix*);
void convert(struct infix*);
int priority(char c);
void show(struct infix);
void strrev(char*);

int main(){
    struct infix q;
    char exp[MAX] = "4 $ 2 * 3 - 3 + 8 / 4 / ( 1 + 1 ) ";
    
    initinfix(&q);
    
    printf("enter an expression in infix form:\n");
    //gets(exp);
    
    printf("%s\n",exp);
    setexpr( &q, exp );
    printf("%s\n",exp);
    
    convert(&q);
    
    printf("The prefix expression is: \n");
    show(q);
    
    //printf("\n%s \n",q.target);
    return 0;
}

void strrev(char *s){
    int len = strlen(s);
    int mid = len/2;
    int i = 0;
    char temp;
    while( i <= mid ){
        temp = s[len-i-1];
        s[len-i-1] = s[i];
        s[i] = temp;
        i++;
    }
    s[len] = '\0'; 
}


//initializes elements of structure variable
void initinfix( struct infix *pq ){
    pq->top = -1;
    strcpy(pq->target, "");
    strcpy(pq->stack,"");
    pq->l = 0;
}

//reverses the given expression
void setexpr(struct infix *pq, char *str)
{
    pq->s = str;
    strrev(pq->s);
    pq->l = strlen(pq->s);
    *(pq->target + pq->l) = '\0';
    pq->t = pq->target + pq->l - 1;
}

//adds operator to stack
void push(struct infix *pq, char c)
{
    if( pq->top == MAX-1 )
        printf("Stack is full\n");
    else{
        pq->top++;
        pq->stack[pq->top] = c;
    }
}

//pops an operator from stack
char pop(struct infix *pq){
    if(pq->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        char item = pq->stack[pq->top];
        pq->top--;
        return item;
    }
}

//convert the infix expr to prefix
void convert(struct infix *pq){
    char opr;
    while(*(pq->s)){
        
        if( *(pq->s) == ' ' || *(pq->s) == '\t'){
            pq->s++;
            continue;
        }
        
        if( isdigit(*(pq->s)) || isalpha(*(pq->s))){
            while(isdigit(*(pq->s)) || isalpha(*(pq->s))){
                *(pq->t) = *(pq->s);
                pq->s++;
                pq->t--;
            }
        }
        
        if(*(pq->s) == ')'){
            push( pq, *(pq->s) );
            pq->s++;
        }
        
        if(*(pq->s) == '*' || *(pq->s) == '+' || *(pq->s) == '/' || *(pq->s) == '%' || *(pq->s) == '-' || *(pq->s) == '$' ){
            if( pq->top != -1){
                opr = pop(pq);
                while( priority(opr) > priority(*(pq->s)) ){
                    *(pq->t) = opr;
                    pq->t--;
                    if( pq->top != -1)
                        opr = pop(pq);
                    else
                        break;
                }
                push(pq, opr);
                push(pq, *(pq->s));
            }
            else
                push( pq, *(pq->s));
                
            pq->s++;
        }
        
        if(*(pq->s) == '('){
            opr = pop(pq);
            while(opr != ')'){
                *(pq->t) = opr;
                pq->t--;
                opr = pop(pq);
            }
            pq->s++;
        }
    }
    
    while(pq->top != -1){
        opr = pop(pq);
        *(pq->t) = opr;
        pq->t--;
    }
    pq->t++;
}

int priority(char c){
    if( c == '$')
        return 3;
    if( c == '*' || c == '/'|| c == '%' )
        return 2;
    if( c == '+'|| c == '-')
        return 1;
    else 
        return 0;
}

void show(struct infix pq){
    while(*(pq.t)){
        printf("%c",*(pq.t));
        pq.t++;
    }
}
