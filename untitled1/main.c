#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char* item_t;

typedef struct hash{
    item_t *table;
    int size;
    int hash_key;
}hash_t;

hash_t *init_hashtable(int m,int key){
    hash_t *tmp = (hash_t *)malloc(sizeof(hash_t));
    tmp->table = (item_t *)malloc(sizeof(item_t)*m);
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
    return key % hashtable->size;
}

unsigned int F(int i){
    return (i+i*i)/2;
}

void insert(hash_t *hashtable,char *text){
    unsigned int key = hash_function(hashtable,text);
    int i;
    item_t tmp = (item_t)malloc(sizeof(char)*TEXTSIZE);
    strcpy(tmp,text);
    for(i=0;;i++){
        int new_key = (key+F(i))%hashtable->size;
        if(hashtable->table[new_key] == NULL) {
            hashtable->table[new_key] = tmp;
            return;
        }
    }
}

unsigned int search(hash_t *hashtable,char *text){
    unsigned int key = hash_function(hashtable,text);
    int i;
    for (i=0;i<hashtable->size;i++){
        int new_key = (key+F(i))%hashtable->size;
        if(hashtable->table[new_key]==NULL) return -1;
        else if(strcmp(hashtable->table[new_key],text)==0)
            return key;
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
