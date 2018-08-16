# include <stdio.h>
# include <stdlib.h>
# define Node node

struct node{
        int data;
        struct node *next;
};

int getIntersectionNode(struct node *head1, struct node *head2){
    struct node *h1 = head1, *h2 = head2;
    
    while( h1->next && h2->next ){
        h1 = h1->next;
        h2 = h2->next;
    }
    while(h1->next){
        head1 = head1->next;
        h1 = h1->next;
    }
    while(h2->next){
        head2 = head2->next;
        h2 = h2->next;
    }
    while(head1 != head2){
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1->data;
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
    /*struct node *head1 = NULL;
    
    push(&head1,5);
    push(&head1,6);
    push(&head1,7);
    push(&head1,8);
    push(&head1,9);
    push(&head1,5);
    push(&head1,6);
    push(&head1,7);
    push(&head1,8);
    push(&head1,9);
    
    struct node *head2 = NULL;
    push(&head2,5);
    push(&head2,6);
    push(&head2,7);
    push(&head2,8);
    push(&head2,9);
    
    head2->next->next->next->next->next = head1->next->next->next->next->next;

    printList(head1);
    printList(head2);
    printf("\nintersection node is %d\n",getIntersectionNode(head1,head2));*/
     
  struct Node* newNode;
  struct Node* head1 =
            (struct Node*) malloc(sizeof(struct Node));
  head1->data  = 10;
 
  struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
  head2->data  = 3;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",getIntersectionNode(head1, head2));
}
