# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void swapNode(struct node **ptr_head, int x, int y){
    struct node *node_x = *ptr_head;
    struct node *node_y = *ptr_head;
    struct node *prev_x = NULL;
    struct node *prev_y = NULL;
    
    if(x==y)
        return;
    
    while(node_x && node_x->data != x ){
        prev_x = node_x;
        node_x = node_x->next;
    }

    while(node_y && node_y->data != y ){
        prev_y = node_y;
        node_y = node_y->next;
    }
    
    if( node_x == NULL || node_y == NULL)
        return;
    
    if( !prev_x )
        *ptr_head = node_y;
    else
        prev_x->next = node_y;
    
    if(!prev_y)
        *ptr_head = node_x;
    else
        prev_y->next = node_x;
      
    struct node *temp = node_x->next;
    node_x->next = node_y->next;
    node_y->next = temp;
    
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
    swapNode(&head,9,5);
    printList(head);
}
