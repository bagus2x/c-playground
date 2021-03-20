#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "hashtable.h"

#define MAX_KEY_LENGTH 10

static uint32_t hash(uint32_t table_size, char *key)
{
    uint32_t hash_value = 0;
    for (int i = 0; i < strnlen(key, MAX_KEY_LENGTH); i++)
    {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % table_size;
    }

    return hash_value;
}

void hashtable_insert(HashTable *ht, Entry *entry)
{
    uint32_t index = hash(ht->table_size, entry->key);

    if (ht->entries[index] != NULL)
    {
        Entry *current = ht->entries[index];
        while (current->next != NULL)
            current = current->next;

        current->next = entry;
        return;
    }

    ht->entries[index] = entry;
}

Entry *hashtable_find(HashTable *ht, char *key)
{
    uint32_t index = hash(ht->table_size, key);

    if (ht->entries[index] != NULL)
    {
        if (strcmp(ht->entries[index]->key, key) == 0)
            return ht->entries[index];

        if (ht->entries[index]->next != NULL)
        {
            Entry *current = ht->entries[index];
            while (current != NULL)
            {
                if (strcmp(current->key, key) == 0)
                    return current;
                current = current->next;
            }
        }
    }

    return NULL;
}

Entry *hashtable_remove(HashTable *ht, char *key)
{
    uint32_t index = hash(ht->table_size, key);
    Entry *current = ht->entries[index];

    if (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            Entry *temp = current;
            ht->entries[index] = current->next;
            return temp;
        }
    }

    while (current->next != NULL)
    {
        if (strcmp(current->next->key, key) == 0)
        {
            Entry *temp = current->next;
            current->next = current->next->next;
            return temp;
        }
        current = current->next;
    }

    return NULL;
}

void hashtable_print(HashTable *ht)
{
    for (int i = 0; i < ht->table_size; i++)
    {
        if (ht->entries[i] == NULL)
        {
            printf("%d EMPTY \n", i);
        }
        else
        {
            if (ht->entries[i]->next != NULL)
            {
                printf("%d", i);

                Entry *current = ht->entries[i];
                while (current != NULL)
                {
                    printf(" { %s : %d } ", current->key, current->value);
                    current = current->next;
                }
                printf("\n");
            }
            else
            {
                printf("%d { %s : %d } \n", i, ht->entries[i]->key, ht->entries[i]->value);
            }
        }
    }
}