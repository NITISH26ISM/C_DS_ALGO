# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

struct node* getTail(struct node* curr){
    while(curr->next)
        curr = curr->next;
    return curr;
}

struct node* partition(struct node *head, struct node* end, struct node **newHead, struct node **newEnd){
    struct node* tail = end, *prev = NULL , *curr = head, *pivot = end;
    
    while(curr != pivot){
        if(curr->data >= pivot->data){
                if(curr == head){
                    head = head->next;
                    tail->next = curr;
                    curr->next = NULL;
                    curr = head;
                    tail = tail->next;
                }
                else{
                    prev->next = curr->next;
                    tail->next = curr;
                    curr->next = NULL;
                    tail = tail->next;
                    curr = prev->next;
                }
        }
        else{
            prev = curr;
            curr = curr->next;
        }
        
    }
    *newHead = head;
    *newEnd = tail;
    return pivot;
    
}

struct node* quickSortRec(struct node *head, struct node* end){
    if(head == NULL || head == end)
        return head;//base case
        struct node *newHead = NULL, *newEnd = NULL;
        struct node *pi = partition(head, end, &newHead, &newEnd);
    
        
        if(pi != newHead){
            struct node *temp = newHead;
            while(temp->next != pi)
                temp = temp->next;
            temp->next = NULL;
            
            newHead = quickSortRec(newHead, temp );
            temp = getTail(newHead);
            temp->next = pi;
        }
        

        pi->next = quickSortRec(pi->next, newEnd);
        return newHead;
}

void quickSort(struct node **headRef){
    (*headRef) = quickSortRec(*headRef, getTail(*headRef));
    return ;
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
    
    push(&head,25);
    push(&head,46);
    push(&head,17);
    push(&head,38);
    push(&head,49);
    push(&head,29);
    
    printList(head);
    
    quickSort(&head);
    
    printList(head);
    
}
