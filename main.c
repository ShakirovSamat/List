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

bool testLen()
{
    List *list = create();
    int counter = 0;

    add(list, 5, 0);
    if (len(list) == 1) ++counter;

    add(list, 6, 0);
    if (len(list) == 2) ++counter;

    add(list, 4, 2);
    if (len(list) == 3) ++counter;

    pop(list, 0);
    if (len(list) == 2) ++counter;

    if (counter == 4)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    if (testLen())
    {
        printf("Len function error!");
        return 0;
    }
    
    return 0;
}