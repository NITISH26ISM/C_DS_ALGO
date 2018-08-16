# include <stdio.h>
# include <stdlib.h>


struct node{
        int data;
        struct node *next;
};

int n = 181;

void findTriplet(struct node *a , struct node* b, struct node* c){
    int sum = 0;
    struct node *_a = a,*_b = b, *_c = c;
    while(a){
        while( b && c ){
            sum = a->data + b->data + c->data;
            if(sum == n ){
                printf("Triplet found: %d , %d, %d\n",a->data,b->data,c->data);
                return;
            }
            else if(sum < n)
                b = b->next;
            else
                c = c->next;
            
        }
        a = a->next;
        b = _b;
        c = _c;
    }
    printf("triplet not found :(");
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
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    push(&head,25);
    push(&head,56);
    push(&head,37);
    push(&head,88);
    push(&head,59);
    
    push(&head1,85);
    push(&head1,76);
    push(&head1,67);
    push(&head1,38);
    push(&head1,19);
    
    push(&head2,5);
    push(&head2,26);
    push(&head2,47);
    push(&head2,68);
    push(&head2,69);
    printList(head);
    printList(head1);
    printList(head2);
    findTriplet(head,head1,head2);
}
