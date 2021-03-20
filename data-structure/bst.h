typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
} Node;

typedef struct BST
{
    struct Node *root;
} BST;

BST *bst_init();

void bst_insert(BST *bst, int data);

void bst_inorder(BST *bst);
