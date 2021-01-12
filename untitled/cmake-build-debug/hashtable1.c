#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item{
    char *text;
    struct item *next;
}item_t;

typedef struct hash{
    item_t **table;
    int size;
    int hash_key;
}hash_t;
/*
13 10 19
1 qwert
1 asdf
1 zklwo
1 a
 */
hash_t *init_hashtable(int m,int key){
    hash_t *tmp = (hash_t *)malloc(sizeof(hash_t));
    tmp->table = (item_t **)malloc(sizeof(item_t *)*m);
    int i;
    for(i=0;i<m;i++)
        tmp->table[i]=NULL;
    tmp->size = m;
    tmp->hash_key = key;
    return tmp;
}

unsigned int hash_function(hash_t *hashtable,char *text){
    int i;
    unsigned int key = 0;
    for(i=0;i<strlen(text);i++)
        key = (unsigned int)(hashtable->hash_key * key) + (unsigned int)text[i];
    //printf("%d",key);
    return key % hashtable->size;
}

item_t *new_item(char *text){
    item_t *tmp = (item_t *) malloc(sizeof(item_t));
    tmp->text = (char *)malloc(sizeof(char)*TEXTSIZE);
    strcpy(tmp->text,text);
    tmp->next = NULL;
    return tmp;
}

void insert(hash_t *hashtable,char *text){
    item_t **item = &hashtable->table[hash_function(hashtable,text)];
    if(*item == NULL) *item = new_item(text);
    else {
        item_t *tmp = new_item(text);
        tmp->next = *item;
        *item = tmp;
    }
}

unsigned int search(hash_t *hashtable,char *text){
    unsigned int key = hash_function(hashtable,text);
    item_t *item = hashtable->table[key];
    while(item != NULL){
        if(strcmp(text,item->text) == 0)
            return key;
        item = item->next;
    }
    return -1;
}

int main(void){
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m,n,i,hash_key;
    int command;

    scanf("%d %d %d", &m,&n,&hash_key);
    hashtable = init_hashtable(m,hash_key);
    text = (char *)malloc(sizeof(char)*TEXTSIZE);

    for(i=0;i<n;i++){
        scanf("%d %s",&command,text);
        switch (command) {
            case 1:
                insert(hashtable,text);
                break;
            case 2:
                printf("%d\n",search(hashtable,text));
                break;
        }
    }
    return 0;
}
