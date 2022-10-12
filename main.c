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

List *create()
{
    List *list = calloc(1,sizeof(List));
    list->head = calloc(1,sizeof(Node));
    return list;
}

int add(List *list, int value,int index)
{
    if (list == NULL || index < 0)
    {
        return -1;
    }
    if (list->head->value == NULL && index == 0)
    {
        list->head->value = value;
        return 0;
    }
    Node *curNode = list->head;
    Node *prevNode = NULL;
    Node *newNode = calloc(1, sizeof(Node));
    newNode->value = value;
    
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
    
    if (i < index - 1)
    {
        return -1;
    }

    if (prevNode == NULL)
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

void printList(List *list)
{
    Node *curNode = list->head;
    printf("List: ");
    while (curNode != NULL)
    {
        printf("%d ", curNode->value);
        curNode = curNode->next;
    }
    printf("\n");
}

bool testAddFunction()
{
    List *list = create();
    if (!add(list, 5, 10)) return false;
    if (!add(list, 5, 0)) return false;
    if (!add(list, 10, 0)) return false;
    if (!add(list, 20, 2)) return false;
    if (!add(list, 30, -3)) return false;
    if (!add(list, 50, 3)) return false;
    if (!add(list, 60, 2)) return false;
    if (!add(list, 70, 1)) return false;

    int res = -1000;
    if (find(list,0, &res) || res != 10) return false;
    if (find(list,0, &res) || res != 70) return false;
    if (find(list,0, &res) || res != 5) return false;
    if (find(list,0, &res) || res != 60) return false;
    if (find(list,0, &res) || res != 20) return false;
    if (find(list,0, &res) || res != 50) return false;
    return true;
}
int main()
{
    if (!testAddFunction)
    {
        printf("Error in add function");
        return -1;
    }
    
    return 0;
}