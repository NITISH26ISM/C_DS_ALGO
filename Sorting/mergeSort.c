# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void FrontBackSplit(struct node* head, struct node **a , struct node **b){
    struct node *fast = head->next, *slow = head;

    while( fast ){
        fast = fast->next;
        if(fast){
            slow = slow->next;
            fast = fast->next;
        }
    }
    (*a) = head;
    (*b) = slow->next;
    slow->next = NULL;
}

struct node* SortedMerge(struct node *a, struct node *b){
    struct node dummy;
    struct node *prev = &dummy;
    while( a && b ){
        if(a->data < b->data){
            prev->next = a;
            a = a->next;
        }
        else{
            prev->next = b;
            b = b->next;
        }
        prev = prev->next; 
    }
    if(a){
        prev->next = a;
    }
    else{
        prev->next = b;
    }
    return dummy.next;
}

void mergeSort(struct node **headRef){
    if( *headRef == NULL || (*headRef)->next == NULL ){
        return;
    }
    //printf("hello");
    struct node *a, *b;
    FrontBackSplit(*headRef, &a, &b );
    
    mergeSort(&a);
    mergeSort(&b);
    
    *headRef = SortedMerge(a,b);
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
    push(&head,0);
    push(&head,89);
    push(&head,23);
    push(&head,33);
    push(&head,59);
        push(&head,5);
    push(&head,36);
    push(&head,79);
    push(&head,18);
    push(&head,49);
    printList(head);
    
    mergeSort(&head);
    printList(head);
}
