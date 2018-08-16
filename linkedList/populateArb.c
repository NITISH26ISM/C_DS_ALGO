# include <stdio.h>
# include <stdlib.h>

struct node{ 
    int data;
    struct node *arb;
    struct node *next;
};

struct node* recur(struct node *head){
    if(head->next == NULL)
        return head;
    
    struct node *max = recur(head->next);
    head->arb = max;
    if(max->data > head->data)
    {
        return max;
    }
    else
        return head;
    
}

void push(struct node **ptr_head, int data){
    struct node *temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *ptr_head;
    temp->arb = NULL;
    *ptr_head = temp;
    
}

void printList(struct node *head){
    while(head->arb != NULL){
        printf("%d->",head->arb->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

int main(){
    struct node *head = NULL;
    
    push(&head,9);
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    
    //printList(head);
    recur(head);
    printList(head);
}
