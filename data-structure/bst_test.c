#include "bst.h"


int main()
{
    BST *bst = bst_init();
    bst_insert(bst, 10);
    bst_insert(bst, 20);
    bst_insert(bst, 5);
    bst_insert(bst, 7);
    bst_insert(bst, 30);
    bst_insert(bst, 1);
    bst_insert(bst, 90);
    bst_insert(bst, 33);
    
    bst_inorder(bst);
}