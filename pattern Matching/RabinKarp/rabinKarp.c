# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

void RabinKarpMatcher( char T[], char P[], int d, int q ){
    int n = strlen(T);
    int m = strlen(P);
    
    
    long long int h = pow( d, m-1 );
    h = h % q;
    int p = 0, t0 = 0;
    
    for( int i = 0; i < m; i++ ){
        p = ( P[i] + d*p );
        t0 = ( T[i] + d*t0 );
        p = (p) % q;
        t0 = (t0) % q;
    }
    
     
    for( int i = 0; i <= n-m ; i++ ){
        if( p == t0 ){
            int j = i, c = 0;
            while( (c < m) && P[c] == T[j] ){
                c++; j++;
            }
            if( c == m ){
                printf("pattern found at %d\n", i);
            }
        }
        if( i < n - m ){
            t0 = ( d*( t0 - T[i]*h ) + T[ i + m ] ) ;
            t0 = t0 %q + q;
        }
        
    }
    
}

int main(){   //123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789
    char T[] = "aaaaaaaaaaabaabaaabbbbbbbbbbbabaababbabaababbbbabaababaabaabaababaabaabbababaabababaabaabaababababababbabaaaababbabab";
    char P[] = "abaababaabaab";
    int d = 10;
    int q = 11;
    
    RabinKarpMatcher( T, P, d, q );
}
