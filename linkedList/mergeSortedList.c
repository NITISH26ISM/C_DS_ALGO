# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

struct node* SortedMerRec(struct node* a, struct node *b){
    
    struct node* result = NULL;
    if( a == NULL )
        return b;
    if( b == NULL )
        return a;
    
    if( a->data <= b->data){
        result = a;
        result->next = SortedMerRec(a->next, b);
    }
    else{
        result = b;
        result->next = SortedMerRec(a, b->next);
    }
    return result;
}

struct node* SortedMerge(struct node * a, struct node *b){
    if( !a )
        return b;
    
    if(!b)
        return a;
    
    struct node *prev = NULL, *curr_a = a, *curr_b = b, *res;
    struct node dummy;
    prev = &dummy;
    while( curr_a && curr_b ){
        
        if(curr_a->data < curr_b->data){
            prev->next = curr_a;
            curr_a = curr_a->next;
        }
        else {
            prev->next = curr_b;
            curr_b = curr_b->next;
        }
        prev = prev->next;
    }
    if(curr_a == NULL)
        prev->next = curr_b;
    else
        prev->next = curr_a;
    
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
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    push(&head1,12);
    push(&head1,8);
    push(&head1,7);
    push(&head1,5);
    push(&head1,2);
    
    push(&head2,11);
    push(&head2,9);
    push(&head2,6);
    push(&head2,3);
    push(&head2,1);
    
    printList(head1);

    printList(head2);
    struct node* res;
    res = SortedMerge(head1,head2);
    printList(res);
}
