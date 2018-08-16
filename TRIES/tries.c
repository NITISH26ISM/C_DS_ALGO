# include <stdio.h>
# include <stdlib.h>

typedef struct vertex{
    int word;
    int prefix;
    struct vertex *edge[26];
}vertex;


typedef struct trie{
    vertex *root;
}trie;


void initialize( vertex *v ){
    v->word = 0;
    v->prefix = 0;
    for( int i = 0; i<26 ; i++)
        v->edge[i] = NULL;
}


void init_trie( trie *T ){
    vertex *tmp = ( vertex* )malloc( sizeof(vertex) );
    initialize(tmp);
    T->root = tmp;
}




void addWord(vertex *v, char word[] ){
    char k = word[0];
    if( k == '\0'){
        v->word++;
        return;
    }
    else 
        v->prefix++;
    
        if(v->edge[ k - 'a'] == NULL){
            vertex *temp = ( vertex* )malloc( sizeof(vertex) );
            initialize(temp);
            v->edge[k - 'a'] = temp;
        }
        
        addWord( v->edge[k - 'a'], word+1 );
}

void find( vertex *v, char word[]){
    char k = word[0];
    if( k == '\0'){
        printf("found\n");
        return;
    }
    else{
        if(v->edge[k - 'a'] == NULL){
            printf("Word not found\n");
            return;
        }
        find(v->edge[k - 'a'], word+1 );
    }
}

int delete(vertex *v, char word[]){
    char k = word[0];
    if( k == '\0'){
        for(int i = 0; i < 26; i++ )
        {
            if( v->edge[i] != NULL)
                return 1;
        }
        free(v);
        return 0;
    }
    else{
        if(v->edge[k - 'a'] == NULL){
            printf("Word not found\n");
            return 1;
        }
        if( delete(v->edge[k - 'a'], word+1 ) == 0){
            v->edge[k - 'a'] = NULL;
            for(int i = 0; i < 26; i++ )
            {
                if( v->edge[i] != NULL)
                    return 1;
            }
            free(v);
            return 0;
        }
        return 1;
    }
}




//Driver Program to test function
int main(){
    trie T;
    init_trie(&T);
    
    addWord(T.root, "facebook");
    addWord(T.root, "facepalm");
    addWord(T.root, "amazon");
    addWord(T.root, "amazing");
    addWord(T.root, "amazonprime");
    addWord(T.root, "amaze");
    addWord(T.root, "amazeon");
    suggest(T.root, "amaz");

    return 0;
}
