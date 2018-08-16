# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

struct node* kAltReverse(struct node* head, int k){
    struct node *prev = NULL, *curr = head, *next = NULL;
    
    int count = 0; 
    while( curr && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    count = 0;
    head->next = next;
    while(next != NULL && count < k){
        curr = next;
        next = next->next;
        count++;
    }
    if(next != NULL){
        curr->next = kAltReverse(next, k);
    }
    
    return prev;
    
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
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int s = sizeof(arr)/sizeof(int);
    //printf("size : %d\n",s);
    for(int i = 1; i <= s; i++  )
        append(&head,i);

    
    printList(head);
    int k = 3;
    struct node *res = kAltReverse(head, k);
    printList(res);
    
}
