#include <stdio.h>
#include "hashtable.h"
#include <stdlib.h>

int main()
{
    Entry *entries[20] = {NULL};
    HashTable ht = {.table_size = 20, .entries = entries};

    Entry ent1 = {.key = "bagus", .value = 3};
    Entry ent2 = {.key = "joni", .value = 1};
    Entry ent3 = {.key = "malik", .value = 2};
    Entry ent4 = {.key = "udins", .value = 38};
    Entry ent5 = {.key = "surbakti", .value = 12};
    Entry ent6 = {.key = "ryzen", .value = 9};
    Entry ent7 = {.key = "ana", .value = 43};
    Entry ent8 = {.key = "ikbal", .value = 6};
    Entry ent9 = {.key = "zuxxy", .value = 73};
    Entry ent10 = {.key = "lem", .value = 48};
    Entry ent11 = {.key = "julia", .value = 93};
    Entry ent12 = {.key = "lembu", .value = 63};
    Entry ent13 = {.key = "uaujs", .value = 23};

    hashtable_insert(&ht, &ent1);
    hashtable_insert(&ht, &ent2);
    hashtable_insert(&ht, &ent3);
    hashtable_insert(&ht, &ent4);
    hashtable_insert(&ht, &ent5);
    hashtable_insert(&ht, &ent6);
    hashtable_insert(&ht, &ent7);
    hashtable_insert(&ht, &ent8);
    hashtable_insert(&ht, &ent9);
    hashtable_insert(&ht, &ent10);
    hashtable_insert(&ht, &ent11);
    hashtable_insert(&ht, &ent12);
    hashtable_insert(&ht, &ent13);

    // hashtable_remove(&ht, "uaujs");
    // hashtable_remove(&ht, "joni");
    // hashtable_remove(&ht, "udins");

    hashtable_print(&ht);

    Entry *res = hashtable_find(&ht, "udins");
    printf("->%s: %s\n", "joni", res != NULL ? "ketemu" : "gak ketemu");

    return 0;
}