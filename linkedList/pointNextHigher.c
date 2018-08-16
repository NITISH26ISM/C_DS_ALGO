# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
        struct node *arb;
};

void printListArb(struct node *head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->arb;
    }
    printf("NULL\n");
    
}

struct node* SortedMerge(struct node *a, struct node *b){
    struct node dummy, *prev;
    prev = &dummy;
    
    while(a && b){
        if(a->data < b->data){
            prev->arb = a;
            a = a->arb;
            prev = prev->arb;
        }else{
            prev->arb = b;
            b = b->arb;
            prev = prev->arb;
        }
    }
    if(a)
        prev->arb = a;
    else
        prev->arb = b;
    
    return dummy.arb;
}

void mergeSort(struct node **headRef ){
    if( *headRef == NULL || (*headRef)->arb == NULL){
        return;
    }
    
    struct node *fast = (*headRef)->arb, *slow = *headRef,*tmp;
    while(fast && fast->arb){
        fast = fast->arb->arb;
        slow = slow->arb;
    }
    tmp = slow->arb;
    slow->arb = NULL;
    struct node *a = *headRef, *b = tmp;
    
    mergeSort(&a);
    mergeSort(&b);
    
    *headRef = SortedMerge(a, b);
    return ;
}


void pointNextHigher(struct node *head){
    struct node *curr = head;
    while(curr){
        curr->arb = curr->next;
        curr = curr->next;
    }
    
    mergeSort(&head);
     printListArb(head);
    
}

void push(struct node **ptr_head, int data){
    struct node *temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *ptr_head;
    temp->arb = NULL;
    
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
    
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,9);
    
    printList(head);
    pointNextHigher(head);
    printList(head);
    
}
