# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

int detectAndRemoveLoop(struct node *head){
    struct node *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            break;
        }
    }
    
    int count = 1;
    fast = fast->next;
    while(fast != slow ){
        count++;
        fast = fast->next;
    }
     //printf("hello %d\n",count);
    count--;
    fast = head, slow = head;
    while(count){
        fast = fast->next;
        count--;
    }
    while(fast->next != slow){
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
    
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
    push(&head,10);
    push(&head,8);
    push(&head,9);
    push(&head,10);
    head->next->next->next->next->next->next->next->next->next = head->next->next->next;
 
   // printList(head);
    detectAndRemoveLoop(head)?printf("Yes\n"):printf("\nNO");
    printList(head);
    
}
