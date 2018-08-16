# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

struct node * sortedIntersect(struct node *a, struct node *b){
    struct node dummy;
    dummy.next = NULL;
    struct node *prev = &dummy;
    while( a && b){
        if(a->data < b->data){
            a = a->next;
        }
        else if(a->data > b->data){
            b = b->next;
        }
        else{
            prev->next = a;
            prev = prev->next;
            a = a->next;
            b = b->next;
        }
    }
    return dummy.next;
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
    
    push(&head,6);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    struct node *head1 = NULL;
    
   // push(&head1,6);
    push(&head1,8);
    push(&head1,6);
    push(&head1,4);
    push(&head1,2);
    

    printList(head);
    struct node* res = sortedIntersect(head,head1);
    printList(res);
}
