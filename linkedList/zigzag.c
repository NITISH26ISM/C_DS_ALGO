# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void zigzagList(struct node **headRef){
    struct node *curr = *headRef, *next = NULL, *prev = NULL, *tmp;
    int flag = 1;
    while(curr->next){
        next = curr->next;
        if((flag == 1 && curr->data < next->data) || (flag == -1 && curr->data > next->data) ){
            prev = curr;
            curr = next;
        }
        else{
            if(prev == NULL){
                curr->next = next->next;
                next->next = curr;
                *headRef = next;
                prev = *headRef;
                curr = prev->next;
            }
            else{
                prev->next = next;
                curr->next = next->next;
                next->next = curr;
                prev = prev->next;
                curr = prev->next;
            }
        }
        flag = flag * (-1);
    }
}


void push(struct node **ptr_head, int data){
    struct node *temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *ptr_head;
    
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
    zigzagList(&head);
    printList(head);
    
}
