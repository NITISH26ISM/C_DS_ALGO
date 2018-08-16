# include <stdio.h>
# include <stdlib.h>
# define Node node

struct node{
        int data;
        struct node *right;
        struct node *down;
};

struct node* SortedMerge(struct node *a, struct node *b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    struct node dummy;
    struct node *prev = &dummy;
    while(a && b){
        if(a->data < b->data){
            prev->down = a;
            a = a->down;
        }
        else{
            prev->down = b;
            b = b->down;
        }
        prev = prev->down;
    }
    if(a)
        prev->down = a;
    if(b)
        prev->down = b;
    
    return dummy.down;
    
}


struct node* flatten(struct node *root){
    if(root == NULL || root->right == NULL)
        return  root;
    return SortedMerge(root, flatten(root->right));
}

void push(struct node **ptr_head, int data){
    struct node *temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->right = NULL;
    temp->down = *ptr_head;
    
    *ptr_head = temp;
    
}


void printList(struct node *head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->down;
    }
    printf("NULL\n");
    
}

//Driver program
int main(){
    struct node *root = NULL;
 
    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );
 
    push( &( root->right ), 20 );
    push( &( root->right ), 10 );
 
    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );
 
    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );
 
    // Let us flatten the list
    
    root = flatten(root);printf("flatened()\n");
 
    // Let us print the flatened linked list
    printList(root);
 
    return 0;
}
