#include "list.h"
#include <stdio.h>
// #include <stdbool.h>



void printNode(struct Node_t* head)
{
    struct Node_t* pt = head;
    while(pt != NULL)
    {
        printf("Data: %d\n", pt->data);
        pt = pt->next;
    }
}

struct Node_t* create_node(int data)
{
    struct Node_t* temp;
    temp = (struct Node_t*)malloc(1* sizeof(struct Node_t));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void pushFront(struct Node_t** head, int data)
{
    struct Node_t* new_node = create_node(data);
    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}

bool push_at(struct Node_t* head, int data, int pos)
{
    struct Node_t* pt = head;
    int i = 0;
    while(pt!=NULL && i!=pos-1)
    {
        pt = pt->next;
        i++;
    }
    if(i!=pos -1)
    {
        return false;
    }
    else
    {
        struct Node_t* _newnode = create_node(data);
        _newnode->next = pt->next;
        pt->next = _newnode;
    }
    return true;
}

void pushBack(struct Node_t** head, int data)
{
    struct Node_t* tmp = *head;
    struct Node_t* newnode = create_node(data);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    while(tmp->next !=NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newnode;
}

void removeHead(struct Node_t** head)
{
    struct Node_t* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}