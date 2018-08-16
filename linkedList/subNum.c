# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define true 1
# define false 0
# define bool int


struct node{
        int data;
        struct node *next;
};

void push(struct node**, int);
void printList(struct node *head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

struct node* newNode(int data){
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = data;
    return tmp;
}

int getCount(struct node *head){
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

struct node* paddZero(struct node* head , int c){
    while(c){
        push(&head, 0);
        c--;
    }
    return head;
}

struct node* subNumRec(struct node *a, struct node *b, int *borrow){
    if( a == NULL && b == NULL && *borrow == 0 )
        return NULL;
    //printf("hi");
    struct node* prev = subNumRec(a ? a->next: NULL, b ? b->next : NULL, borrow);
    
    int d1 = a->data;
    int d2 = b->data;
    int sub = 0;
    //printf("hi");
    if(*borrow){
        d1--;
        *borrow = false;
    }
    
    if( d1 < d2 ){
        d1 += 10;
        *borrow = true;
    }
   // printf("hi");
    sub = d1 - d2;
    struct node* curr = newNode(sub);
    curr->next = prev;
    return curr;
}

struct node* subNum(struct node *a, struct node* b){
    if(a == NULL && b == NULL )
        return NULL;
    
    int count_a = getCount(a);
    int count_b = getCount(b);
    
    struct node *temp_a, *temp_b, *lNode = NULL, *sNode = NULL;
    temp_a = a;
    temp_b = b;
    
    if(count_a != count_b){
        lNode = (count_a > count_b)? a : b;
        sNode = (count_a > count_b)? b : a;
        sNode = paddZero(sNode, abs(count_a-count_b));
    }
    else{
        while( a && b){
            if(a->data != b->data){
                lNode = (a->data > b->data)? temp_a : temp_b;
                sNode = (a->data > b->data)? temp_b : temp_a;
                break;
            }
            a = a->next;
            b = b->next;
        }
    }
    int borrow = false;

    return subNumRec(lNode, sNode , &borrow);
}

void push(struct node **ptr_head, int data){
    struct node *temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *ptr_head;
    
    *ptr_head = temp;
    
}

void insertAfter(struct node *prev_node, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = prev_node->next;
    prev_node->next = temp;
}

void append(struct node **ptr_head, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(*ptr_head == NULL){
        *ptr_head = temp;
        return;
    }
    struct node *last = *ptr_head;
    while(last->next){
        last = last->next;
    }
    last->next = temp;
}



//Driver program
int main(){
    struct node *head = NULL, *head1 = NULL;
    
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,9);
    
    push(&head1,5);
    push(&head1,6);
    push(&head1,7);
    push(&head1,8);
    //push(&head1,9);
    
    printList(head);
    printList(head1);
    struct node* res = subNum(head, head1);
    printList(res);
}
