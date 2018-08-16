# include <stdio.h>
# include <stdlib.h>
# include <math.h>

struct node{
        int data;
        struct node *next;
};
void printList(struct node *head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

int carry(struct node* a){
    if(a->next == NULL){
        if(a->data >= 10 ){
            a->data = (a->data)%10;
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int c = carry(a->next);
    a->data +=  c;
    if(a->data >= 10 ){
        a->data = (a->data)%10;
        return 1;
    }
    else{
        return 0;
    }
    
}

int countNode(struct node* x){
    if(x == NULL)
        return 0;
    
    int count = 1;
    while(x->next){
        count++;
        x = x->next;
    }
    return count;
}
struct node* addNumRec(struct node *a ,struct node *b){
    if(a->next == NULL){
        a->data = a->data + b->data;
        return a;
    }
    
    a->next = addNumRec(a->next, b->next);
    a->data = a->data + b->data;
    
    return a;
}
struct node dummy;

struct node* addNum(struct node *a ,struct node *b){
    int count_a = countNode(a);
    int count_b = countNode(b);
    
    struct node *tmp = a;
    if(count_a < count_b){
        a = b;
        b = tmp;
        int t = count_a;
        count_b = count_a;
        count_a = count_b;
    }
    int diff = count_a - count_b ;
   // printf("count %d\n",diff);
    dummy.next = a;
    a = &dummy;
    
    while(diff){
        a = a->next;
        diff--;
    }
    
    a->next = addNumRec(a->next , b);
    // printList(dummy.next);
    int c = carry(dummy.next);
    if(c){
        dummy.data = c ;
        return &dummy;
    }
    else{
        return dummy.next;
    }
    
}

void push(struct node **ptr_head, int data){
    struct node *temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *ptr_head;
    
    *ptr_head = temp;
    
}



//Driver program
int main(){
    struct node *head = NULL,*head1 = NULL;
    
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,9);
    
    push(&head1,5);
    push(&head1,6);
    push(&head1,7);
    push(&head1,8);
    push(&head1,9);
    
    printList(head);printf("\n");
    printList(head1);printf("\n");
    
    struct node* res = addNum(head,head1);
    printList(res);
    
}
