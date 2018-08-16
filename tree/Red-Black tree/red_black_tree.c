# include <stdio.h>
# include <stdlib.h>

enum Color{ red, black } ;
typedef struct rbNode{
    int key;
    Color color;
    struct rbNode* left;
    struct rbNode* right;
    struct rbNode* p;
}rbNode;

typedef struct rbTree{
    rbNode *root;
    rbNode *nil;
}rbTree;

void init_rbTree(rbTree* T){
    T->nil = ( rbNode* )malloc( sizeof(rbNode) );
    T->nil->color = black;
    T->root = T->nil;
}

void leftRotate(rbTree *T, rbNode *x){
    rbNode *y = x->right;
    x->right = y->left;
    if(y->left != T->nil){
        y->left->p = x;
    }
    y->p = x->p;
    if(x->p == T->nil)
        T->root = y;
    else if(x->p->left == x)
        x->p->left = y;
    else
        x->p->right = y;
    y->left = x;
    x->p = y;
}

void rightRotate(rbTree *T, rbNode *x){
    rbNode *y = x->left;
    x->left = y->right;
    if(y->right != T->nil)
        y->right->p = x;
    y->p = x->p;
    if( x->p == T->nil)
        T->root = y;
    else if(x->p->left == x)
        x->p->left = y;
    else 
        x->p->right = y;
    
    y->right  = x;
    x->p = y;
}


rbNode* newNode(int key){
    rbNode* z = ( rbNode* )malloc( sizeof(rbNode) );
    z->key = key;
    z->color = red;
    return z;
}

void insert(rbTree *T, int key){
    rbNode *z = newNode(key);
    rbNode *y = T->nil;
    rbNode *x = T->root;
    while( x != T->nil ){
        y = x;
        if(z->key < x->key)
            x = x->left;
        else 
            x = x->right;
    }
    z->p = y;
    if(y == T->nil)
        T->root = z;
    else if( z->key < y->key )
        y->left = z;
    else
        y->right = z;
    
    z->left = T->nil;
    z->right = T->nil;
    
    ///////////fix-up
    
    
    while( z->p->color == red ){
        if(z->p == z->p->p->left){
            y = z->p->p->right;
            if( y->color == red ){
                z->p->p->color = red;
                z->p->color = black;
                y->color = black;
                z = z->p->p;
            }
            else{
                if(z == z->p->right){
                    z = z->p;
                    leftRotate(T,z);
                }
                z->p->color = black;
                z->p->p->color = red;
                rightRotate(T, z->p->p);
            }
        }
        else{
            y = z->p->p->left;
            if( y->color == red){
                z->p->p->color = red;
                z->p->color = black;
                y->color = black;
            }
            else{
                if(z == z->p->left){
                    z = z->p;
                    rightRotate(T,z);
                }
                z->p->color = black;
                z->p->p->color = red;
                leftRotate(T, z->p->p);
            }
        }
    }
    T->root->color = black;
}

void inorder(rbNode *root, rbNode *nil){
    if(root == nil)
        return;
    inorder(root->left, nil);
    //printf("Node Color: %d, value %d \n",root->color ,root->key);
    printf("%d ", root->key);
    inorder(root->right, nil);
}

rbNode* search(rbTree *T, int key ){
    rbNode *r = T->root;
    while( r != T->nil ){
        if( r->key == key){
            return r;
        }
        else if( r->key > key){
            r = r->left;
        }
        else
            r = r->right;
    }
    
    printf("\nKey not found :-(\n");
    return NULL;
}


rbNode* TreeMin(rbTree *T, rbNode *x){
    while(x->left != T->nil){
        x = x->left;
    }
    return x;
}

void Transplant(rbTree *T,rbNode *v, rbNode *u){
    if( v->p == T->nil){
        T->root = u;
    }
    else if( v->p->left == v)
        v->p->left = u;
    else 
        v->p->right = u;
    u->p = v->p;
}

void rb_delete_fix_up(rbTree *T, rbNode *x ){
    rbNode *w;
    while( x != T->root && x->color == black){
        if( x->p->left == x ){
            w = x->p->right;
            if( w->color == red){
                w->color = black;
                x->p->color = red;
                leftRotate(T, x->p);
                w = x->p->right;
            }
            if( w->left->color == black && w->right->color == black ){
                w->color = red;
                x = x->p;
            }
            else{
                if(w->right->color == black){
                    w->left->color = black;
                    w->color = red;
                    rightRotate(T, w);
                    w = x->p->right;
                }
                
                w->color = x->p->color;
                x->p->color = black;
                w->right->color = black;
                leftRotate(T, x->p);
                x = T->root;
            }
        }
        else{
            w = x->p->left;
            if( w->color == red){
                w->color = black;
                x->p->color = red;
                rightRotate(T, x->p);
                w = x->p->left;
            }
            if( w->right->color == black && w->left->color == black ){
                w->color = red;
                x = x->p;
            }
            else{
                if(w->left->color == black){
                    w->right->color = black;
                    w->color = red;
                    leftRotate(T, w);
                    w = x->p->left;
                }
                
                w->color = x->p->color;
                x->p->color = black;
                w->left->color = black;
                rightRotate(T, x->p);
                x = T->root;
            }            
        }
        
    }
    
    x->color = black;
}


void _delete(rbTree *T, int key){
    rbNode *z = search(T, key);
    rbNode *x, *y = z;
    
    enum Color y_original_color = y->color;
    
    if(z->left == T->nil){
        x = z->right;
        Transplant(T,z,x);
    }
    else if(z->right == T->nil){
        x = z->left;
        Transplant(T,z,x);
    }
    else{
        y = TreeMin(T, z->right);
        y_original_color = y->color;
        x = y->right;
        if(y->p == z){
            x->p = y;
        }
        else{
            Transplant(T, y, x);
            y->right = z->right;
            y->right->p = y;
        }
        Transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }
    
    if(y_original_color == black)
        rb_delete_fix_up(T, x);
}



//Driver program to test the func
int main(){
    rbTree T;
    init_rbTree(&T);
    insert(&T, 10);
    insert(&T, 20);
    insert(&T, 30);
    insert(&T, 9);
    insert(&T, 210);
    insert(&T, 89);
    insert(&T, 76);
    insert(&T, 15);
    insert(&T, 1);
    insert(&T, 57);
    insert(&T, 28);
    insert(&T, 64);
    
    inorder(T.root,T.nil);
    printf("\n");
    _delete( &T, 10);
    inorder(T.root,T.nil);
    printf("\n");
    return 0;
}

