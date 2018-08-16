# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *arb;
}node;

void printList(node* );
node* cloneLinkList(node* head){
    node* h1 = head, *h2, *temp;
    
    while(h1 != NULL){
        temp = (node*)malloc(sizeof(node));
        temp->data = h1->data;
        temp->next = h1->next;
        temp->arb = h1->arb;

        h1->next = temp;
        h1 = temp->next;
    }
    //printList(head);
    h1 = head->next;
    
    while(h1->next != NULL){
        h1->arb = h1->arb->next;
        h1 = h1->next->next;
    }
    h1 = head;
    h2 = head->next;
    temp = h2; 
    while(h2->next){
        h1->next = h1->next->next;
        h2->next = h2->next->next;
        h1 = h1->next;
        h2 = h2->next;
        
    }
    h1->next = NULL;
    
    return temp;
}

void push(node **headRef, int data ){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = *headRef;
    tmp->arb = NULL;
    *headRef = tmp;
}

void printList(node* head){
    node* temp = head;
    while(head!=NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\nArb Pointer:\n");
    
    while(temp != NULL){
        printf("%d->%d\n",temp->data,temp->arb->data);
        temp = temp->next;
    }
}


int main(){
    node* head = NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    head->arb = head->next->next;
    head->next->arb = head;
    head->next->next->arb = head->next->next->next->next;
    head->next->next->next->arb = head->next->next;
    head->next->next->next->next->arb = head->next;
    
    printList(head);
    node* clone = cloneLinkList(head);
    printList(clone);
    
}
