# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

int searchRec(struct node *head, int key){
    if(head == NULL)
        return 0;
    
    if(head->data == key)
        return 1;
    else
        return searchRec(head->next , key);
}


int search(struct node *head, int key){
    while( head && head->data != key){
        head = head->next;
    }
    if(head){
        return 1;
    }else
        return 0;
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
    
    printList(head);
    insertAfter(head->next->next,1);
    printList(head);
    append(&head,0);
    printList(head);
    int key = 7;
    printf("is %d in the list: ",key);
    searchRec(head, key)?printf("YES\n"):printf("NO\n");
}
