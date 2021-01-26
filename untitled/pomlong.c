#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[4][5];
    int n =0;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++) {
            a[i][j] = i;
            n++;
        }
    }
    //int *p = a;
    for(int i=0;i<20;i++){
        printf("%d\n",**(a+i));
    }

    return 0;
}