# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void deleteNode(struct node **ptr_head, int key){
    struct node *temp = *ptr_head, *prev;
    if(temp != NULL && temp->data == key ){
        *ptr_head = temp->next;
        free(temp);
        return;
    }
    while( temp != NULL && temp->data != key ){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)    return;
    prev->next = temp->next;
    free(temp);
}

void deleteNodePos(struct node **ptr_head, int pos){
    struct node *temp = *ptr_head;
    if(*ptr_head == NULL)
        return;
    
    if(pos == 0){
        *ptr_head = temp->next;
        free(temp);
        return;
    }
    
    while( temp->next != NULL && pos > 1 ){
        temp = temp->next ;
        pos--;
    }
    if(temp->next == NULL && pos >= 1)
        return;
    
    struct node *del_node = temp->next;
    temp->next = del_node->next;
    free(del_node);
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
    insertAfter(head->next->next,1);
    printList(head);
    append(&head,0);
    printList(head);
    deleteNode(&head,9);
    printList(head);
    deleteNodePos(&head, 3);
    printList(head);
}
