#include "hashtable.h"

int main(){
    hash_table *ht = ht_new();
    delete_hash_table(ht);
    
    return 0;
}