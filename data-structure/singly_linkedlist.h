typedef struct Node
{
    struct Node *next;
    int data;
} Node;

typedef struct LinkedList
{
    struct Node *root;
    struct Node *tail;
    int size;
} LinkedList;

void llinsert(LinkedList *list, int data);

void llremove(LinkedList *list, int index);

void llprint(LinkedList *list);

LinkedList *llinit();

LinkedList *llfree(LinkedList *list);

int llpeak(LinkedList *list);