# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void removDup(struct node* head){
    unordered_set <int> seen;
    struct node* curr = head;
    struct node* prev = NULL;
    while(curr != NULL){
        if(seen.find(curr->data) != seen.end() ){
            prev->next = curr->next;
            free(curr);
        }
        else{
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
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
    
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,9);
    

    printList(head);
}
