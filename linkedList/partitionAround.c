# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void printList(struct node *head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}


struct node* partition(struct node *head, int x){
    struct node *smallerHead = NULL, *smallerLast = NULL, *greaterHead = NULL, *greaterLast = NULL, *equalHead = NULL, *equalLast = NULL;
    
    while(head != NULL){
            if(head->data == x){
                if(equalHead == NULL){
                    equalHead = equalLast = head;
                }
                else{
                    equalLast->next = head;
                    equalLast = equalLast->next;
                }
            }
            else if(head->data < x){
                if(smallerHead == NULL){
                    smallerHead = smallerLast = head;
                }
                else{
                    smallerLast->next = head;
                    smallerLast = smallerLast->next;
                }
            }
            else{
                if(greaterHead == NULL){
                    greaterHead = greaterLast = head;
                }
                else{
                    greaterLast->next = head;
                    greaterLast = greaterLast->next;
                }
            }
        
            head = head->next;
    }
    if(greaterLast != NULL)
        greaterLast->next = NULL;
    
    if(smallerHead == NULL){
        if(equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }
    
    if(equalHead == NULL){
        smallerLast->next = greaterHead;
        return smallerHead;
    }
    
    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    return smallerHead;
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


//Driver program
int main(){
    struct node *head = NULL;
    
    push(&head,3);
    push(&head,2);
    push(&head,5);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,1);
    int x = 3;
    //1->4->3->2->5->2->3,
    printList(head);
    head = partition(head,x);
    printList(head);
    
}







