# include <stdio.h>
# include <stdlib.h>
# define SIZE(x) (sizeof(x)/sizeof(int))
# define Node node
struct node{
    int data;
    struct node *next;
    struct node *child;
};

void flattenList(struct node* head){
    if( head == NULL )
        return ;
    
    struct node *tail = head, *curr = head, *tmp;
    while(tail->next)
        tail = tail->next;
    
    while(curr != tail){
        if(curr->child != NULL){
            tail->next = curr->child;
            
            tmp = curr->child;
            while(tmp->next)
                tmp = tmp->next;
            tail = tmp;
            
        }
        curr = curr->next;
    }
}


void printList(struct node *head){
    while(head){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *List(int *arr, int n)
{
    struct Node *head = NULL;
    struct Node *p;
 
    int i;
    for (i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = (struct Node *)malloc(sizeof(struct node));
        else {
            p->next = (struct Node *)malloc(sizeof(struct node));
            p = p->next;
        }
        p->data = arr[i];
        p->next = p->child = NULL;
    }
    return head;
}
 

struct node* createList(void){
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};
    
    struct Node *head1 = List(arr1, SIZE(arr1));
    struct Node *head2 = List(arr2, SIZE(arr2));
    struct Node *head3 = List(arr3, SIZE(arr3));
    struct Node *head4 = List(arr4, SIZE(arr4));
    struct Node *head5 = List(arr5, SIZE(arr5));
    struct Node *head6 = List(arr6, SIZE(arr6));
    struct Node *head7 = List(arr7, SIZE(arr7));
    struct Node *head8 = List(arr8, SIZE(arr8));
    
    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;
    
    return head1;
}

int main(){
    struct node* head = NULL;
    head = createList();
    flattenList(head);
    printList(head);
    
}
