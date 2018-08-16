# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void SegEvenOdd(struct node **headRef){
    struct node *last = *headRef, *tail , *tmp = *headRef, *head = *headRef, *prev = NULL;
    while(last->next)
        last = last->next;
    tail = last;
    
    while(tmp != last){
        
        if((tmp->data)&1){//odd
            if(*headRef == tmp ){
                tail->next = tmp;
                *headRef = tmp->next;
                tmp->next = NULL;
                tail = tail->next;
                tmp = *headRef;
            }
            else{
                tail->next = tmp;
                prev->next = tmp->next;
                tmp->next = NULL;
                tail = tail->next;
                tmp = prev->next;
            }
        }
        else{//even
            prev = tmp;
            tmp = tmp->next;
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
    
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,9);
    push(&head,52);
    push(&head,69);
    push(&head,17);
    push(&head,84);
    push(&head,91);
    
    printList(head);
    SegEvenOdd(&head);
    printList(head);
    
}
