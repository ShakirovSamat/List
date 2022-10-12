#include <malloc.h>
#include <stdbool.h>

typedef struct 
{
    int value;
    struct Node *next;
}Node;

typedef struct 
{
    Node *head;
}List;

int find(List *list, int index, int *res)
{
    if (list == NULL || index < 0)
    {
        return -1;
    }

    Node *curNode = list->head;
    Node *prevNode = NULL;    
    int i = 0;
    while (i < index)
    {
        if (curNode->next == NULL)
        {
            break;
        }
        prevNode = curNode;
        curNode = curNode->next;
        ++i;
    }
    if (curNode->next == NULL && i < index - 1)
    {
        return -1;
    }
    *res = curNode->value; 
}

int main()
{
    return 0;
}