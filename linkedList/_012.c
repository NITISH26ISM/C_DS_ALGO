# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void sort(struct node **headRef){
    struct node dummy1, dummy2;
    dummy1.data = 0;
    dummy1.next = &dummy2;
    dummy2.data = 1;
    dummy2.next = *headRef;
    struct node *head = &dummy1, *last = *headRef, *prev = &dummy2, *curr = *headRef, *tail, *tmp, *t;
    
    while(last && last->next)
        last = last->next;
    
    tail = last;
    
    while(curr != last){
        if(curr->data == 0){
            tmp = head->next;
            head->next = curr;
            t = curr->next;
            curr->next = tmp;
            curr = t;
            prev->next = t;
            prev = prev->next;
            
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
    
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
    
    printList(head);
    sort(&head);
    printList(head);
    
}
