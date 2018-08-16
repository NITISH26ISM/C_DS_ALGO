# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void skipMdeleteN(struct node *head, int m, int n){
    struct node *prev = NULL, *curr = head, *tmp;
    int count;
    while(curr){
        count = 0;
        while(curr && count < m){
            prev = curr;
            curr = curr->next;
            count++;
        }
        count = 0;
        while(curr && count < n){
            tmp = curr;
            curr = curr->next;
            free(tmp);
            count++;
        }
        prev->next = curr;
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
    skipMdeleteN(head,1,2);
    
    printList(head);
    
}
