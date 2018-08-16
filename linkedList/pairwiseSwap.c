# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

void pairWiseSwap(struct node **ptr_head){
    if( !(*ptr_head) || !((*ptr_head)->next) )
        return;
    
    struct node *first = *ptr_head, *sec = (*ptr_head)->next, *tmp;
    *ptr_head = (*ptr_head)->next;
    while(first && sec){
        tmp = sec->next;
        sec->next = first;
        first->next = NULL;
        if(tmp == NULL )
            break;
        else if(tmp->next){
            first->next = tmp->next;
            first = tmp;
            sec = tmp->next;
            continue;
        }
        else{
            first->next = tmp;
            first = tmp;
            sec = NULL;
            continue;
        }

    }
    

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
   // push(&head,11);
    

    printList(head);
    pairWiseSwap(&head);
    printList(head);
}
