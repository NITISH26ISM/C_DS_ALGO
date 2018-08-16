# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

struct node* addNum(struct node *a ,struct node *b){cout<<"hell";
    struct node* res = NULL,*tmp,*prev;
    int sum = 0  , carry = 0;
    while( a || b ){
        sum = carry + (a?a->data:0) + (b?b->data:0);
        carry = (sum >= 10)? 1 : 0 ; 
        sum = sum % 10;
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data = sum;
        
        if(res == NULL){
            res = tmp;
        }
        else{
            prev->next = tmp;
        }
        prev = tmp;
        if(a)
            a = a->next;
        if(b)
            b = b->next;
        
    }
    
    if(carry){
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data = carry;
        prev->next = tmp;
    }
 
    return res;
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

void printRev(struct node *head){
    if(head == NULL ){
        return;
    }
    printRev(head->next);
    printf("%d",head->data);
    return;
        
}

void printList(struct node *head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

//Driver program
int main(){
    struct node *head = NULL,*head1 = NULL;
    
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,9);
    
    push(&head1,5);
    push(&head1,6);
    push(&head1,7);
    push(&head1,8);
    push(&head1,9);
    
    printRev(head);printf("\n");
    printRev(head1);printf("\n");
    
    struct node* res = addNum(head,head1);
    printRev(res);
    
}
