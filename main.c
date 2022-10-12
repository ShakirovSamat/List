#include <stddef.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct 
{
    int value;
    struct Node *next;
}Node;

typedef struct 
{
    Node *head;
}List;

List* create()
{
    List *list = calloc(1,sizeof(List));
    list->head = calloc(1,sizeof(Node));
    return list;
}

int pop(List *list, int index)
{  
    if (list == NULL)
    {
        return;
    }

    int length = len(list);
    printf("%d", length);

    if (index >= length ||index < 0)
    {
        return;
    }         

    Node *current = list->head;  
    Node *previous = NULL;

    int value = 0;
    int i = 0;
    

    while (i != index && current != NULL)
    { 
        previous = current;
        current = current->next;
        ++i;
    } 

    value = current->value;

    if (index == 0)
    {
        list->head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    free(current);

    return value;
}

bool testPopFunction()
{
    bool error = false;

    List *list = create();

    add(list, 10, 0);
    add(list, 5, 0);
    add(list, 15, 0);
    add(list, 100, 0);

    int length = len(list);
    pop(list, 4);
    if (length > len(list))
    {
        error = true;
    }

    pop(list, -1);
    if (length > len(list))
    {
        error = true;
    }

    int value = pop(list, 0);
    if (length == len(list) || value != 100)
    {
        error = true;
    }

    length = len(list);
    value = pop(list, 1);
    if (length == len(list) || value != 5)
    {
        error = true;
    }

    return error;
}

int main()
{
    if (testPopFunction())
    {
        printf("Pop function error.\n");
        return 0;
    }

    return 0;
}