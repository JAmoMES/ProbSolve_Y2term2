#include <stdio.h>

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int a[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

void insertion_sort(int a[],int n){
    int i,j;
    for(i=1;i<n;i++){
        for(j=i;j>=1;j--){
            if(a[j]<a[j-1])
                swap(&a[j],&a[j-1]);
            else break;
        }
        print_array(a,n);
    }
}

int main(){
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertion_sort(a,n);
    return 0;
}