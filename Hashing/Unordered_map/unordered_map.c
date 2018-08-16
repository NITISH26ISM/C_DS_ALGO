# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct node{
    char *s;
    int count;
    struct node* next;
}node;

node* newNode(char str[]){
    node* temp = (node*)malloc(sizeof(node) );
    temp->count = 1;
    temp->next = NULL;
    int i;
    temp->s = (char*)malloc(strlen(str)+1);
    for( i = 0; str[i] != '\0'; i++)
        temp->s[i] = str[i];
    temp->s[i] = '\0';
    return temp;
}

typedef struct unordered_map{
    node** list;
    int size;
}unordered_map;

void init_unordered_map(unordered_map *m ){
    m->list = ( node** )malloc( 1010*sizeof(node*) );
    
    for( int i = 0; i < 1010; i++ ){
        m->list[i] = NULL;
    }
    
    m->size = 0;
}

void insert(unordered_map* m, char s[]){
    int temp = 0,d  = 10, q = 1009;
    for( int j = 0; s[j] != '\0'; j++ )
    {
        temp = ( s[j] + temp * d );
        temp = temp % q;
    }
    
   // printf("%d \n", temp);
    if( m->list[temp] == NULL ){
        m->list[temp] = newNode(s);
    }
    else{
        node *t = m->list[temp], *prev;
        int test = strcmp( s, t->s );
        while( t != NULL && test ){
            prev = t;
            t = t->next;
            test = strcmp( s, t->s );
        }
        if(t){
            t->count++;
        }
        else{
            prev->next = newNode(s);
        }
    }
    m->size++;
}

int count(unordered_map *m, char s[]){
    int temp = 0,d  = 10, q = 1009;
    for( int j = 0; s[j] != '\0'; j++ )
    {
        temp = ( s[j] + temp * d );
        temp = temp % q;
    }
    
    if( m->list[temp] == NULL ){
        return 0;
    }
    else{
        node *t = m->list[temp], *prev;
        int test = strcmp( s, t->s );
        while( t != NULL && test ){
            prev = t;
            t = t->next;
            test = strcmp( s, t->s );
        }
        if(t){
            return t->count;
        }
        else{
            return 0;
        }
    }
}

int main(){
    char word[6][10] = { "abcvsd", "skdfh", "nitish", "nitish", "bansal" , "makkicho"};
    
    unordered_map m;
    init_unordered_map( &m );
    
    int i = 2e9;
    printf("%d",i);
}
