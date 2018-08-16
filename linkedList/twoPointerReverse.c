# include <stdio.h>
# include <stdlib.h>

// two pointer xor method;
//Author : Nitish Kumar
struct node{
        int data;
        struct node *next;
};

struct node* XOR(struct node* a, struct node *b){
    return (struct node*)((size_t)(a) ^ (size_t)(b));
}

void reverse(struct node **headRef){
    struct node* curr = (*headRef)->next, *xor = *headRef;
    xor = XOR(xor,curr);
    while(curr){
        xor = XOR(xor,curr->next);
        curr->next = XOR(XOR(xor,curr),curr->next);
        xor = XOR(xor,curr->next);
        curr = XOR(xor,curr);
    }
    
    (*headRef)->next = NULL;
    *headRef = xor;
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
    struct node *head = NULL;
    
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,9);
    
    printList(head);
    reverse(&head);
    printList(head);
    
}
