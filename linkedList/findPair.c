# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* XOR(struct node* a , struct node *b){
    return (struct node*)( (size_t)(a) ^ (size_t)(b) );
}

void findPair(struct node *head, int x){
    struct node *prev = head, *curr = head->next, *next = head->next->next, *end,*tmp;
    while(next){
        curr->next = XOR(prev , next);
        prev = curr;
        curr = next;
        next = next->next;
    }
    end = curr;
    curr->next = prev;
    int sum = 0;
    next = head->next;
    prev = end->next;
    
    while(head != end){
       
        sum = head->data + end->data; // printf("%d %d\n",head->data, end->data);
        if(sum == x){
            printf("pair found : %d %d\n",head->data, end->data);
            tmp = next;
            next = XOR((next->next),head);
            head = tmp;
            if(head == end)
                break;
            tmp = prev;
            prev = XOR((prev->next), end);
            end = tmp;
        }
        else if(sum < x){
            tmp = next;
            next = XOR((next->next), head);
            head = tmp;
        }
        else if(sum > x){
            tmp = prev;
            prev = XOR((prev->next), end);
            end = tmp; 
        }
    }
    
    return;
}


void push(struct node **headRef,int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = *headRef;
    *headRef = tmp;
}

void printList(struct node* head){
    while(head){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct node *head = NULL;
    push(&head,11);
    push(&head,10);
    push(&head,9);
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,3);
    
    int x = 17;
    printList(head);
    findPair(head, x);
    
    return 0;
}
