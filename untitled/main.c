#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree{
    int frequency;
    char word[16];
    struct tree *left;
    struct tree *right;
}tree_t;

typedef struct heap{
    tree_t **t;
    int last;
}heap_t;

tree_t *getnode(){
    tree_t *tmp = (tree_t *)malloc(sizeof(tree_t));
    scanf("%s",tmp->word);
    scanf("%d",&tmp->frequency);
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

heap_t *init(int n){
    heap_t *tmp = (heap_t *)malloc(sizeof(heap_t));
    tmp->t = (tree_t **)malloc(sizeof(tree_t *)*(n+1));
    int i;
    for(i=0;i<=n;i++){
        tmp->t[i] = NULL;
    }
    tmp->last = 0;
    return tmp;
}

void swap(tree_t **heap,int i,int j){
    tree_t *tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

void insert(heap_t *mh,tree_t *new){
    tree_t **heap = mh->t;
    int last = mh->last++;
    heap[++last] = new;
    int i;
    for(i = last;i/2>0;i/=2){
        if(heap[i]->frequency < heap[i/2]->frequency)
            swap(heap,i,i/2);
        else return;
    }
}

tree_t *delete_min(heap_t *mh){
    tree_t **heap = mh->t;
    if(mh->last == 0) return NULL;
    int last = mh->last--;
    tree_t *tmp = heap[1];
    swap(heap,1,last--);
    int i = 1;
    while(i*2 <= last){
        if(i*2 == last) {
            if (heap[i]->frequency > heap[2 * i]->frequency)
                swap(heap,i,2*i);
            break;
        }
        if(heap[2*i]->frequency <= heap[2*i+1]->frequency)
            if(heap[i]->frequency > heap[2*i]->frequency) {
                swap(heap, i, 2 * i);
                i = i*2;
            }
            else break;
        else if(2*i+1 <= last)
            if(heap[i]->frequency > heap[2*i+1]->frequency) {
                swap(heap, i, 2 * i + 1);
                i = i*2 +1 ;
            }
            else break;
    }
    return tmp;
}

void bfs(heap_t *mh){
    tree_t **heap = mh->t;
    int last = mh->last;
    int i;
    for(i=1;i<=last;i++)
        printf("%s:%d ",heap[i]->word,heap[i]->frequency);
    printf("\n");
}

void dfs(tree_t *t,char code[]){
    if(t == NULL) return;
    if(t->left==NULL && t->right ==NULL)
        printf("%s : %s\n",t->word,code);
    char ncode[10000];
    strcpy(ncode,code);
    dfs(t->left,strcat(ncode,"0"));
    strcpy(ncode,code);
    dfs(t->right,strcat(ncode,"1"));
}

int main(){
    int i,n,f;
    scanf("%d",&n);
    heap_t *heap = init(n);
    for(i=0;i<n;i++){
        tree_t *tmp = getnode();
        insert(heap,tmp);
        //printf("%d %d\n",i,n);
        //bfs(heap);
    }
    bfs(heap);
    for(i=0;i<n-1;i++){
        tree_t *a = delete_min(heap);
        tree_t *b = delete_min(heap);
        tree_t *tmp = (tree_t *)malloc(sizeof(tree_t));
        tmp->frequency = a->frequency + b->frequency;
        tmp->left = a;
        tmp->right = b;
        insert(heap,tmp);
    }
    //bfs(heap);
    char code[n+1];
    dfs(heap->t[1],strcpy(code,""));
    return 0;
}
/*
 9
 a 1
 e 2
 g 1
 h 2
 i 3
 m 1
 s 5
 t 1
 _ 3

 */