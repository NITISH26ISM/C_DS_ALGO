#include <stdio.h>
# include <string.h>

int main(){
    char s[] = "miku"+"\0";
    int len = strlen(s);
    printf("len : %d",len);
    return 0;
}
