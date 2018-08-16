# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int key;
    int ht;
    struct node *left;
    struct node *right;
}node;

node* newNode( int );
int max( int, int );
int getBalance(node*);
int height(node*);
node* leftRotate(node*);
node* rightRotate(node*);
node* insert(node *, int);
void inorder(node*);
node* delete(node* , int);

//Testing and Debugging


int main(){
    struct node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    
    inorder(root);
    root = delete(root, 30);
    printf("\n");
    inorder(root);
    printf("\n");
    return 0;
}

node* newNode(int key){
    node* temp = (node*)malloc(sizeof(node));
    temp->key = key;
    temp->ht = 1;
    temp->left = NULL;
    temp->right = NULL;
}

int max( int a, int b){
    return (a > b) ? a : b; 
}

int getBalance(node *n){
    return height(n->left) - height(n->right);
}

int height(node *N){
    if( N == NULL){
        return 0;
    }
    return N->ht;
}

node* leftRotate( node* y ){
    node *x = y->right;
    y->right = x->left;
    x->left = y;
    
    y->ht = 1 + max( height(y->left), height(y->right));
    x->ht = 1 + max( height(x->left), height(x->right));
    
    return x;
}

node* rightRotate( node* y){
    node *x = y->left;
    y->left = x->right;
    x->right = y;
    
    y->ht = 1 + max( height(y->left), height(y->right));
    x->ht = 1 + max( height(x->left), height(x->right));
    
    return x;
}

node* insert(node *Node, int key){
    
    if(Node == NULL)
        return newNode(key);
    
    else if( key < Node->key){
        Node->left = insert(Node->left, key);
    }
    
    else if( key > Node->key){
        Node->right = insert(Node->right, key);
    }
    else
        return Node;
    
    Node->ht = 1 + max( height(Node->left), height(Node->right) ); 
    
    int balance = getBalance(Node);
    
    if( balance > 1 && key < Node->left->key )
        return rightRotate(Node);
    
    if( balance < -1 && key > Node->right->key )
        return leftRotate(Node);
    
    if( balance > 1 && key > Node->left->key )
    {
        Node->left = leftRotate(Node->left);
        return rightRotate(Node);
    }
    
    if( balance < -1 && key < Node->right->key ){
        Node->right = rightRotate(Node->right);
        return leftRotate(Node);
    } 
    
    return Node;
}


void inorder(node* root){
    if( root == NULL )
        return;
    printf("%d ", root->key);
    inorder(root->left);
    
    inorder(root->right);

}

node* delete(node* root, int key){
    if(root == NULL)
        return NULL;
    
    if( root->key > key){
        root->left = delete(root->left, key);
    }
    else if( root->key < key ){
        root->right = delete(root->right, key);
    }
    else if( root->key == key ){
        if( root->left == NULL || root->right == NULL ){
            node *temp = (root->left) ? root->left : root->right;
            if( temp == NULL ) //leaf node
            {
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
            }
            free(temp);
           // printf("\n succ: %d\n",root->left);
            
        }
        else{
            node *succ = root->right;
            while(succ->left){
                succ = succ->left;
            }
           // printf("\n succ: %d\n",succ->key);
            root->key = succ->key;
            
            root->right = delete(root->right, succ->key);
         //   printf("\n succ: %d\n",succ->key);
        }
        
        if( root == NULL )
            return NULL;
        
        root->ht = 1 + max( height(root->left), height(root->right) );
        int balance = getBalance(root);
        //printf("\n height: %d\n", balance);
        if( balance > 1 && getBalance(root->left) >= 0 ){
            return rightRotate(root);
        }
        else if( balance > 1 && getBalance(root->left) < 0){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        else if( balance < -1 && getBalance(root->right) <= 0){
            return leftRotate(root);
        }
        else if( balance < -1 && getBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
        
    }
    
    
}
