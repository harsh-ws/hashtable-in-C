#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

// Allocate a chunk of memory the size of an hash_table_item & save
// the copy of strings k & v in this memory.
static hash_table_item* ht_new_item(const char* k, const char* v){
    hash_table_item* item = malloc(sizeof(hash_table_item));
    item->key = strdup(k);
    item->value = strdup(v);
    return item;
}
