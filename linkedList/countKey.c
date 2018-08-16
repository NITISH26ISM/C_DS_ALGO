# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

int countKey(struct node* head, int key){
    if(head == NULL)
        return 0;
    if(head->data == key)
        return 1 + countKey(head->next, key);
    else
        return countKey(head->next, key);
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
    
    push(&head,1);
    push(&head,2);
    push(&head,1);
    push(&head,2);
    push(&head,1);
    
    printList(head);
    insertAfter(head->next->next,1);
    printList(head);
    append(&head,0);
    printList(head);
    int key = 2;
    printf("the key %d repeats in list %d times",key, countKey(head,key));
}
