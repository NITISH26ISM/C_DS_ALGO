# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

struct node* sortedMerge(struct node *a, struct node *b){
    struct node *head = NULL, *temp; 
    while(a && b){
        if(a->data < b->data){
            temp = a->next;
            a->next = head;
            head = a;
            a = temp;
        }else{
            temp = b->next;
            b->next = head;
            head = b;
            b = temp;
        }
    }
    while(a){
            temp = a->next;
            a->next = head;
            head = a;
            a = temp;
    }
    while(b){
            temp = b->next;
            b->next = head;
            head = b;
            b = temp;
        
    }
    
    return head;
}

void push(struct node **ptr_head, int data){
    struct node *temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *ptr_head;
    
    *ptr_head = temp;
    
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
    
    push(&head,50);
    push(&head,46);
    push(&head,37);
    push(&head,28);
    push(&head,19);
    
    struct node *head1 = NULL;
    push(&head1,35);
    push(&head1,26);
    push(&head1,17);
    push(&head1,15);
    push(&head1,9);
    
    printList(head);
    printList(head1);
    struct node* res = sortedMerge(head, head1);
    printList(res);
    
}
