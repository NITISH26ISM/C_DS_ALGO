# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int x;
    int y;
    struct node *next;
}node;

node* delMidPointsRec(node *head){
    if( head->next->next == NULL){
        return head->next;
    }
    
    node *tmp = delMidPointsRec(head->next);
    if(tmp->x == head->x || tmp->y == head->y){
        node* f = head->next;
        head->next = tmp;
        free(f);
    }
    return head->next;
}

void delMidPoints(node* head){
    node *curr = head->next, *prev = head, *next = head->next->next;
    
    while(next != NULL){
        if(prev->x == curr->x && curr->x == next->x){
            prev->next = curr->next;
            free(curr);
            curr = next;
            next = next->next;
        }
        else if(prev->y == curr->y && curr->y == next->y){
            prev->next = curr->next;
            free(curr);
            curr = next;
            next = next->next;
        }else{
            prev = curr;
            curr = next;
            next = next->next;
        }
    }
    
}

void push(node **headRef, int x, int y){
    node* tmp = ( node* )malloc(sizeof( node ));
    tmp->x = x;
    tmp->y = y;
    tmp->next = *headRef;
    *headRef  = tmp;
}

void printList(node* head){
    while(head){
        printf("(%d,%d)-->",head->x, head->y);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    node *head = NULL;
    push(&head, 40,5);
    push(&head, 20,5);
    push(&head, 7,5);
    push(&head, 7,10);
    push(&head, 5,10);
    push(&head, 1,10);
    push(&head, 0,10);

    printList(head);
    delMidPointsRec(head);
    
    printList(head);
}
