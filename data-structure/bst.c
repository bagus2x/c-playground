#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void inorder_tracks(Node *node);

BST *bst_init()
{
    BST *bst = (BST *)malloc(sizeof(BST));

    return bst;
}

void bst_insert(BST *bst, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;

    Node *current = bst->root;
    if(current == NULL) {
        bst->root = node;
        return;
    }

    Node *parent = NULL;
    while (current != NULL)
    {
        parent = current;
        if (data > current->data)
        {
            current = current->right;
            if (current == NULL)
                parent->right = node;
        }
        else
        {
            current = current->left;
            if (current == NULL)
                parent->left = node;
        }
    }
}

void bst_inorder(BST *bst)
{
    inorder_tracks(bst->root);
}

void inorder_tracks(Node *node)
{
    if(node != NULL)
    {
        inorder_tracks(node->left);
        printf("%d\n", node->data);
        inorder_tracks(node->right);
    }
}