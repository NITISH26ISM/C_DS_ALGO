# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

struct node *sortAbsoluteSorted(struct node *head){
    struct node *tail = head, *curr = head, *next = NULL;
    while(curr->next){
        if(curr->next->data < 0){
            next = curr->next;
            curr->next = next->next;
            next->next = tail;
            tail = next;
        }
        else{
            curr = curr->next;
        }
    }
    return tail;
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
        printf("(%d)->",head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

//Driver program
int main(){
    struct node *head = NULL;
    
    push(&head,9);
    push(&head,-8);
    push(&head,-7);
    push(&head,6);
    push(&head,5);
    
    printList(head);
    head = sortAbsoluteSorted(head);
    printList(head);
    
    
}
