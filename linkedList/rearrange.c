# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void rearrange(struct node *head){
    struct node *fast = head->next, *slow = head;
    
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    struct node *prev = NULL, *curr = slow->next, *next;
    slow->next = NULL;
    while(curr){//printf("hi");
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    curr = prev;
    while(head && curr){
        slow  = head->next;
        fast  = curr->next;
        head->next  = curr;
        curr->next = slow;
        head = slow;
        curr = fast;
    }
    
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
    
    push(&head,10);
    push(&head,9);
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    printList(head);
    rearrange(head);
    printList(head);
    
}
