# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void alternateSplit(struct node *head , struct node **a, struct node **b){
    *a = head;
    *b = head->next;
    
    struct node *tmp = *b;
    while( *b && (*b)->next ){
        (*a)->next = (*b)->next;
        (*a) = (*a)->next;
        (*b)->next = (*a)->next;
        (*b) = (*b)->next;
    }
    if(*b){
        (*a)->next = NULL;
        (*b)->next = NULL;
    }
    else{
        (*a)->next = NULL;
    }
    
    (*a) = head;
    (*b) = tmp; 
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

void printList(struct node *head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

//Driver program
int main(){
    struct node *head = NULL, *a = NULL, *b = NULL;
    
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,9);
    push(&head,10);
    
    printList(head);
    alternateSplit( head , &a , &b );
    
    printf("Resultant linked list is: ");
    printList(a);
    
    printf("Resultant linked list is: ");
    printList(b);
}
