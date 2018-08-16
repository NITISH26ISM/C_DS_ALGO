# include <stdio.h>
# include <stdlib.h>
# include <string.h>


void calculateLPSArray(char P[], int lps[], int m){
    int i , j;
    i = 1;
    j = 0;
    lps[0] = 0;
    while( i < m ){
        if( P[i] == P[j] ){
            lps[i] = j + 1;
            i++;
            j++;
        }
        else{
            if( j != 0 ){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
        
    }
    
}

void printLPS(int lps[], int m){
    for( int i = 0; i < m ; i++){
        printf("%d ",lps[i]);
    }
    printf("\n");
}

int main(){   //123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789
    char T[] = "aaaaaaaaaaabaabaaabbbbbbbbbbbabaababbabaababbbbabaababaabaabaababaabaabbababaabababaabaabaababababababbabaaaababbabab";
    char P[] = "abaababaabaab";
    int m = strlen(P);
    int lps[m];
    
    //preprocessing O(m)
    calculateLPSArray( P, lps, m );
    
    int t = 0, p = 0 ;
    int n = strlen(T);
    //printf("%d \n",n);
    while( t < 100){
        if( p == m){
            printf("Found at %d .\n", t - m);
        }
        
        if( T[t] == P[p] ){
            t++;
            p++;
        }
        else{
            if( p != 0)
                p = lps[p-1];
            else{
                t++;
            }
        }
    }
    return 0;
}
