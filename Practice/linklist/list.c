#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(struct list_t* head)
{
    struct list_t* pt = head;
    while(pt != NULL)
    {
        printf("Data: %d\n", pt->data);
        pt = pt->next;
    }
}
struct list_t* create_node_of_list(int data)
{
    struct list_t* _temp = (struct list_t*)malloc(sizeof(struct list_t));
    _temp->data = data;
    _temp->next = NULL;
    return _temp;
}

void pust_front(struct list_t** head, int data)
{
    struct list_t* _new = create_node_of_list(data);
    if(*head == NULL)
    {
        *head = _new;
    }
    else
    {
        _new->next = *head;
        *head = _new;
    }
}

void pust_back(struct list_t** head, int data)
{
    struct list_t* _new = create_node_of_list(data);
    struct list_t* _temp = *head;
    if(*head == NULL)
    {
        *head = _new;
    }
    else
    {
        while(_temp->next!=NULL)
        {
            _temp = _temp->next;
        }
        _temp -> next = _new;
    }
}