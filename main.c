#include <stddef.h>
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

List *create()
{
    List *list = calloc(1,sizeof(List));
    list->head = calloc(1,sizeof(Node));
    return list;
}

int len(List *list)
{
    if (list == NULL)
    {
        return 1;
    }
    Node *currentNode = list->head;
    int length = 0;
    while (currentNode != NULL)
    {
        ++(length);
        currentNode = currentNode->next;
    }

    return length;
}

bool testLenFunction()
{
    List *list = create();
    add(list, 10, 0);
    add(list, 15, 0);
    add(list, 30, 0);
    if (lenList(list) == 3)
    {
        return true;
    }
    return false;
}

int main()
{
    return 0;
}