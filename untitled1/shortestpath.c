#include <stdio.h>
#include <stdlib.h>
#define INFINITE 100000;

int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int u,v,w,i,j,k,s,t;
    int **a;
    a = (int **) malloc(sizeof(int *)*n);
    for(i=0;i<n;i++)
        a[i] = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j] = INFINITE;
            if(i==j) a[i][j]=0;
        }
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        a[u][v] = w;
        a[v][u] = w;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(a[i][k] > a[i][j] + a[j][k])
                    a[i][k] = a[i][j] + a[j][k];
    for(i=0;i<p;i++){
        scanf("%d %d",&s,&t);
        if(a[s][t] == 100000)
            printf("-1\n");
        else
            printf("%d\n",a[s][t]);
    }
    return 0;
}
/*
7 7 7
 0 4 12
 1 0 12
 2 1 12
 2 3 12
 3 6 20
 6 5 40
 5 0 30
 0 6
 0 4
 2 5
 5 2
 3 4
 5 3
 1 6



 */