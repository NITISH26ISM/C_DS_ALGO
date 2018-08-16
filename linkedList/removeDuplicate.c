# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void removeDuplicates(struct node *head){
    struct node *current = head, *next = head->next, *tmp;
    while(current->next){
        if(current->data == next->data){
            tmp = next;
            next = next->next;
            current->next = next;
            free(tmp);
        }else{
            tmp = next;
            next = next->next;
            current = tmp;
        }
    }
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
    
    push(&head,60);
    push(&head,43);
    push(&head,43);
    push(&head,21);
    push(&head,11);
    push(&head,11);
    push(&head,11);
    
    printList(head);
    removeDuplicates(head);
    printList(head);
}
