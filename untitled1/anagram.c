#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 51
#define HASHKEY 7

typedef struct node{
    char *c;
    struct node *next;
}node_t;

typedef struct item{
    char *c;
    struct node *inside;
}item_t;

typedef struct hash{
    item_t *table;
    int size;
    int hash_key;
}hash_t;

hash_t *init_hashtable(int m,int key){
    hash_t *tmp = (hash_t *)malloc(sizeof(hash_t));
    tmp->table = (item_t *)malloc(sizeof(item_t)*m);
    int i;
    for(i=0;i<m;i++) {
        tmp->table[i].c = NULL;
        tmp->table[i].inside = NULL;
    }
    tmp->size = m;
    tmp->hash_key = key;
    return tmp;
}

void merge(char arr[], int l, int m, int r) {
    int i, j, k;
    int nl = m-l+1;
    char L[nl];
    int nr = r-m;
    char R[nr];
// Copy data to temporary L and R arrays
    for (i=0; i<nl; i++)
        L[i] = arr[l+i];
    for (j=0; j<nr; j++)
        R[j] = arr[m+1+j];
// Merge the L and R arrays back into arr
    i = 0; j = 0; k = l;
    while (i < nl && j < nr)
        arr[k++] = (L[i]<=R[j])? L[i++] : R[j++];
// Copy the remaining elements, if any
    while (i < nl)
        arr[k++] = L[i++];
    while (j < nr)
        arr[k++] = R[j++];
}

void merge_sort(char arr[], int l, int r) {
    int m;
    if (l < r) {
        m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

unsigned int hash_function(hash_t *hashtable,char *text){
    int i;
    unsigned int key = 0;
    for(i=0;i<strlen(text);i++)
        key = (unsigned int)(hashtable->hash_key * key) + (unsigned int)text[i];
    return key % hashtable->size;
}

unsigned int F(int i){
    return (i+i*i)/2;
}

void insert(hash_t *hashtable,char *text){
    char sort_text[51];
    strcpy(sort_text,text);
    merge_sort(sort_text,0,strlen(sort_text)-1);
    unsigned int key = hash_function(hashtable,sort_text);
    char *tmp = (char *)malloc(sizeof(char)*TEXTSIZE);
    strcpy(tmp,sort_text);
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->c = (char *)malloc(sizeof(char)*TEXTSIZE);
    strcpy(node->c,text);
    node->next = NULL;
    int i;
    for(i=0;;i++){
        int new_key = (key+F(i))%hashtable->size;
        if(hashtable->table[new_key].c == NULL) {
            hashtable->table[new_key].c = tmp;
            hashtable->table[new_key].inside = node;
            return;
        }
        else if(strcmp(hashtable->table[new_key].c,sort_text)==0){
            node->next = hashtable->table[new_key].inside;
            hashtable->table[new_key].inside = node;
            return;
        }
    }
}

void print_anagram(node_t *node){
    if(node == NULL) return ;
    print_anagram(node->next);
    printf("%s ",node->c);
}

void search(hash_t *hashtable,char *text){
    char sort_text[51];
    strcpy(sort_text,text);
    merge_sort(sort_text,0,strlen(sort_text)-1);
    unsigned int key = hash_function(hashtable,sort_text);
    int i;
    for (i=0;i<hashtable->size;i++) {
        int new_key = (key + F(i)) % hashtable->size;
        if (hashtable->table[new_key].c == NULL) break;
        else if (strcmp(hashtable->table[new_key].c, sort_text) == 0) {
            print_anagram(hashtable->table[new_key].inside);
            break;
        }
    }
    printf("\n");
}

int main(void){
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m,n,i;

    scanf("%d %d", &m,&n);
    hashtable = init_hashtable(m,HASHKEY);
    text = (char *)malloc(sizeof(char)*TEXTSIZE);
    for(i=0;i<m;i++){
        scanf("%s",text);
        insert(hashtable,text);
    }
    for(i=0;i<m;i++){
        printf("%d %s\n",i,hashtable->table[i].c);
        node_t *node = hashtable->table[i].inside;
        while(node != NULL){
            printf(" %s",node->c);
            node = node->next;
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        scanf("%s",text);
        search(hashtable,text);
    }
    return 0;
}
