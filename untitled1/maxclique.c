#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    if(a>b) return a;
    return b;
}

int is_clique(int n,int **g,int *store){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i;j<n-1;j++){
            if(g[store[i]][store[j]] == 0)
                return 0;
        }
    }
    return 1;
}

int max_clique(int i,int l,int **g,int n,int *store){
    int maxx = 0,j;
    for(j = i;j<n;j++){
        store[l]=j;
        if(is_clique(l+1,g,store)){
            maxx = max(maxx,l);
            maxx = max(maxx,max_clique(j,l+1,g,n,store));

        }
    }
    return maxx;
}

int main(){
    int i,j,n,m,u,v;
    scanf("%d %d",&n,&m);
    int **g = (int **) malloc(sizeof(int *)*n);
    for(i=0;i<n;i++)
        g[i] = (int *)malloc(sizeof(int)*n);
    int *store = (int *)malloc(sizeof(int)*(n+1));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) {
            g[i][j] = 0;
        }
        store[i+1]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u][v]=1;
        g[v][u]=1;
    }
    printf("%d",max_clique(0,1,g,n,store));
    return 0;
}
