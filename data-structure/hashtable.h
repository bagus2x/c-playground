#include <inttypes.h>

typedef struct Entry
{
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct HashTable
{
    Entry **entries;
    uint32_t table_size;
} HashTable;

void hashtable_insert(HashTable *ht, Entry *entry);

Entry *hashtable_find(HashTable *ht, char *key);

Entry *hashtable_remove(HashTable *ht, char *key);

void hashtable_print(HashTable *ht);