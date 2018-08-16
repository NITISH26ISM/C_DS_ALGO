# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *down;
}node;

node* flattenList(node *head){
    if(head == NULL)
        return NULL;
    
    //printf("%d\n",head->data);
    struct node* tmp = head, *next = head->next;
    
    head->next = flattenList(head->down);
    
    while(head->next != NULL)
        head = head->next;
    
    head->next = flattenList(next);
    
    return tmp;
}

node* newNode(int new_data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = new_node->down = NULL;
    return new_node;
}

void printList(struct node *head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

int main(){
    node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->down = newNode(7);
    head->next->down->down = newNode(9);
    head->next->down->down->down = newNode(14);
    head->next->down->down->down->down = newNode(15);
    head->next->down->down->down->down->next
                                     = newNode(23);
    head->next->down->down->down->down->next->down
                                      = newNode(24);
    head->next->down->next = newNode(8);
    head->next->down->next->down = newNode(16);
    head->next->down->next->down->down = newNode(17);
    head->next->down->next->down->down->next
                                      = newNode(18);
    head->next->down->next->down->down->next->next
                                      = newNode(19);
    head->next->down->next->down->down->next->next->next
                                      = newNode(20);
    head->next->down->next->down->down->next->next->next->down
                                      = newNode(21);
    head->next->down->next->next = newNode(10);
    head->next->down->next->next->down = newNode(11);
 
    head->next->down->next->next->next = newNode(12);
 
    // Flatten list and print modified list
    //printList(head);
    head = flattenList(head);
    printList(head);

    return 0;
}
