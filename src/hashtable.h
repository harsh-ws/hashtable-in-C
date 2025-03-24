#include <_string.h>
#include <math.h>

typedef struct{
    char* key;
    char* value;
}hash_table_item;

// Hash Function
static int hash_function(const char* s, const int prime, const int m){
    long hash = 0;
    const int len = strlen(s);
    for (int i=0; i<len; i++){
        hash += (long)(pow(prime,len - (i+1)) * s[i]);
        hash = hash % m;
    }
    return (int)hash;
}

typedef struct{
    int size;
    int count;
    hash_table_item** items;
}hash_table;


void insert(hash_table* ht, const char* key, const char* value);
char* search(hash_table* ht, const char* key);
char* delete(hash_table* ht, const char* key);



