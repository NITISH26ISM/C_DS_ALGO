# include <stdio.h>
# include <stdlib.h>


struct node{
        char key;
        struct node *next;
};

int compString(struct node *a, struct node *b){
    while(a && b){
        if(a->key == b->key){
            a = a->next;
            b = b->next;
        }
        else{
            if( (a->key - b->key) < 0 )
                return -1;
            else
                return 1;
        }
    }
    if(!a && !b)
        return 0;
    else if(a)
        return 1;
    else 
        return -1;
}

void push(struct node **ptr_head, char data){
    struct node *temp = (struct node* )malloc(sizeof(struct node));
    temp->key = data;
    temp->next = *ptr_head;
    
    *ptr_head = temp;
}

void printList(struct node *head){
    while(head != NULL){
        printf("%c->",head->key);
        head = head->next;
    }
    printf("NULL\n");
    
}

//Driver program
int main(){
    struct node *head = NULL, *head1 = NULL;
    
    push(&head,'g');
    push(&head,'e');
    push(&head,'e');
    push(&head,'k');
    push(&head,'s');
    
    push(&head1,'g');
    push(&head1,'e');
    push(&head1,'e');
    push(&head1,'k');
    push(&head1,'s');
    
    printList(head);
    printList(head1);
    
    printf("%d\n",compString(head, head1));
    
    return 0;
}
