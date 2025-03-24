#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

#define PRIME1 2223
#define PRIME2 5557

static hash_table_item HT_DELETED_ITEM = {NULL,NULL};


// Allocate a chunk of memory the size of an hash_table_item & save
// the copy of strings k & v in this memory.
static hash_table_item* ht_new_item(const char* k, const char* v){
    hash_table_item* item = malloc(sizeof(hash_table_item));
    item->key = strdup(k);
    item->value = strdup(v);
    return item;
}

// Initialise a new hash table.
hash_table* ht_new(){
    hash_table* ht = malloc(sizeof(hash_table));
    ht->size = 51;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(hash_table_item*));
    return ht;
}

// Delete the hash table item
static void hash_table_del_item(hash_table_item* item){
    free(item->key);
    free(item->value);
    free(item);
}

// Delete the hash table
void delete_hash_table(hash_table* ht){
    for (int i=0; i<ht->size; i++){
        hash_table_item *item = ht->items[i];
        if (item != NULL)
            hash_table_del_item(ht);
    }
    free(ht->items);
    free(ht);
}

static int hashed(const char* s, const int a, const int m){
    long hash = 0;
    const int len = strlen(s);
    for (int i=0; i < len; i++){
        hash += (long) pow(a, len - (i+1) * s[i]);
        hash = hash % m;
    }
    return (int)hash;
}

static int get_hash(const char* s, const int num_buckets, const int attempt){
    const int hash_a = hashed(s, PRIME1, num_buckets);
    const int hash_b = hashed(s, PRIME2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

void insert(hash_table* ht, const char* key, const char* value){
    hash_table_item* item = ht_new_item(key, value);
    int index = get_hash(item->key, ht->size, 0);
    hash_table_item* curr_item = ht->items[index];
    int i = 1;
    while (curr_item != NULL){
        index = get_hash(item->key, ht->size, i);
        curr_item = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
}

void search(hash_table* ht, char* key){
    int index = get_hash(key, ht->size, 0);
    hash_table_item* item = ht->items[index];
    int i = 1;
    while (item != NULL){
        if (strcmp(item->key,key) == 0)
            return item->value;
        index = get_hash(key,ht->size,i);
        item = ht->items[index];
        i++;
    }
    return NULL;
}

void delete(hash_table* ht, char* key){
    int index = get_hash(key, ht->size, 0);
    hash_table_item* item = ht->items[index];
    int i = 1;
    while (item != NULL){
        if (item != DELE)
    }
}

int main(){
    hash_table* ht = ht_new();
    delete_hash_table(ht);

}