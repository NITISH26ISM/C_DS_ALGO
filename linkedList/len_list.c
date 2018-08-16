# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

int getCountRec(struct node * head){
    if(head==NULL)
        return 0;
    
    return 1+getCountRec(head->next);
}

int getCount(struct node *head){
    int count = 0;
    while( head != NULL){
        head = head->next;
        count++;
    }
    return count;
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
    printf("\ntotal node in list is : %d\n",getCount(head));
    printf("\ntotal node in list is : %d\n",getCountRec(head));
}
