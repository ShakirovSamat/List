#include <stddef.h>
#include <malloc.h>


typedef struct 
{
    int value;
    struct Node *next;
}Node;

typedef struct 
{
    Node *head;
}List;

int add(List *list, int value,int index)
{
    if (list == NULL)
    {
        return -1;
    }
    if(list->head->value == NULL)
    {
        list->head->value = value;
        return 0;
    }
    Node *curNode = list->head;
    Node *prevNode = NULL;
    Node *newNode = calloc(1, sizeof(Node));
    newNode->value = value;
    
    int i = 0;
    while(i < index)
    {
        if(curNode->next == NULL)
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

    if(prevNode == NULL)
    {
        newNode->next = curNode;
        list->head = newNode;
    }
    else if (curNode->next == NULL){
        curNode->next = newNode;
    }
    else
    {
        prevNode->next = newNode;
        newNode->next = curNode;
    }

    return 0;

}

int main()
{
    return 0;
}