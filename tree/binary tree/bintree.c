# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int key;
    int element;
    struct node *left;
    struct node *right;
}node;


node* newNode( int data ){
    struct node* new = (node*)malloc( sizeof(node) );
    new->key = data;
    new->left = NULL;
    new->right = NULL;
    
    return new;
}

void preorder(node *root){
    
    if(root == NULL)
        return;
    
   
    preorder(root->left);
    
    preorder(root->right);
     printf("%d ", root->key);
}



int main(){
    node *root = newNode(1);
    
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    
    preorder(root);
    getchar();
    return 0;
}
