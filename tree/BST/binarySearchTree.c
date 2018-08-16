# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int key;
    struct node *p;
    struct node *right;
    struct node *left;
}node;

void deleteNode( node **pRoot, node *del ){
    node *parent = del->p;
    node *temp;
    int flag = 0;
    if( del == *pRoot){
        temp = (node*)malloc(sizeof(node));
        temp->right = NULL;
        temp->left = del;
        temp->p = NULL;
        del->p = temp;
        parent = temp;
        flag = 1;
        
    }

    if(del->left == NULL && del->right == NULL){
        if(parent->left == del)
            parent->left = NULL;
        else
            parent->right = NULL;
        
        free(del);
        if(flag)
            *pRoot = temp->left;
        return;
    }
    else if( del->left == NULL || del->right == NULL){
        if(parent->left == del)
            parent->left = (del->left == NULL) ? del->right : del->left ;
        else
            parent->right = (del->left == NULL) ? del->right : del->left ;
        
        free(del);
        if(flag)
            *pRoot = temp->left;
        return;
    }
    else{
        node *predecessor = del->left;
        while(predecessor->right)
            predecessor = predecessor->right;
        

        node* prePar = predecessor->p;
        if(prePar->left == predecessor)
            prePar->left = predecessor->left;
        else
            prePar->right = predecessor->left;
        
        predecessor->left = del->left;
        predecessor->right = del->right;
        predecessor->p = del->p;
        
        if(parent->left == del)
            parent->left = predecessor;
        else
            parent->right = predecessor;
        
       
        
        free(del);
        if(flag){
            *pRoot = parent->left;
        }
        return;
    }
}

node* find(node *root, int key){
    while(root != NULL){
        if( root->key == key ){
            return root;
        }
        else if( root->key < key){
            root = root->right;
            continue;
        }
        else{
            root = root->left;
            continue;
        }
    }
    
    printf("Key not found!\n");
    return NULL;
}



void insertion(node **pRoot, int key){
    node *y = NULL;
    node *x = *pRoot;
    
    while( x != NULL ){
        y = x;
        if( key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    
    node *temp = (node*)malloc(sizeof(node));
    temp->key = key;
    temp->p = y;
    temp->left = NULL;
    temp->right = NULL;
    
    if( y == NULL)
        *pRoot = temp;
    else{
        if( temp->key < y->key)
            y->left = temp;
        else 
            y->right = temp;
    }
    
}

void inorder( node *root ){
    if(root == NULL)
        return;
    else{
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

node* TreeMinimum(node *root){
    while(root->left)
        root = root->left;
    
    return root;
}

node* TreeMaximum(node *root){
    while(root->right){
        root = root->right;
    }
    return root;
}

node* TreeSuccessor(node *p){
    if( p->right != NULL){
        return TreeMinimum(p->right);
    }
    else{
        node *y = p;
        p = p->p;
        while(p != NULL && p->left != y){
            y = p;
            p = p->p;
        }
        return p;
    }
}

node* TreePredecesor(node *p){
    if( p->left != NULL )
        return TreeMaximum(p->right);
    else{
        node* y = p;
        p = p->p;
        while( p != NULL && p->right != y){
            y = p;
            p = p->p;
        }
        return p;
    }
}

int main(){
    node *root = NULL;
    insertion( &root, 10 );
    insertion( &root, 14 );
    insertion( &root, 9 );
    insertion( &root, 5 );
    insertion( &root, 20 );
    insertion( &root, 19 );
    insertion( &root, 6 );
    insertion( &root, 26 );
    
    inorder(root);
    node * suc = TreeSuccessor(root);
    node * min = TreeMinimum(root);
    node *max  =  TreeMaximum(root);
    printf("\nsucc : = %d",suc->key);
    printf("\nmin : = %d",min->key  );
    printf("\nmax := %d\n", max->key);
    node *del = find(root, 10);
    deleteNode(&root, del);
    inorder(root);
    
    return 0;
}



