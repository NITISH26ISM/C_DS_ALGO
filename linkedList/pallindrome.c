# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};
void printList(struct node*);

void reverseList(struct node **ptr_head){
    struct node *prev = NULL, *current = *ptr_head , *next;
    
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *ptr_head = prev;
}

int isPallindrome(struct node *head){
    struct node *slow = head, *fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast){
        slow = slow->next;
    }
    
    reverseList(&slow);
    printList(head);
    struct node *tmp = slow;
    while( tmp ){
        if(tmp->data != head->data){
            reverseList(&slow);
            return 0;
        }
        tmp = tmp->next;
        head = head->next;
    }
    reverseList(&slow);
    return 1;
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
    push(&head,6);
    push(&head,5);
    push(&head,8);
    push(&head,6);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    
    printList(head);

    isPallindrome(head)?printf("Yes\n"):printf("No\n");
    return 0;
}
