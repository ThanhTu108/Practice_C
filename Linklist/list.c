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
int size(struct Node_t* head)
{
    int cnt = 0;
    while(head!=NULL)
    {
        ++cnt;
        head = head->next;
    }
    return cnt;
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

void push_at(struct Node_t* head, int data, int pos)
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
        printf("Err insert!");
        return;
    }
    else
    {
        struct Node_t* _newnode = create_node(data);
        _newnode->next = pt->next;
        pt->next = _newnode;
    }
}

void insert(struct Node_t** head, int data, int pos)
{
    int n = size(*head);
    if(pos < 0 || pos > n)
    {
        return;
    }
    if(pos == 0)
    {
        pushFront(head, data);
        return;
    }
    struct Node_t* _temp = *head;
    for(int i = 0; i < pos-1; i++)
    {
        _temp = _temp->next;
    }
    //_temp: pos-1
    struct Node_t* newnode = create_node(data);
    newnode->next = _temp->next;
    _temp->next = newnode;
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

void popFront(struct Node_t** head)
{
    struct Node_t* _temp;
    _temp = *head;  //free first node
    if(*head == NULL)
    {
        return;
    }
    (*head) = (*head)->next;
    free(_temp);
}

void popBack(struct Node_t** head)
{
    if(*head == NULL)
    {
        return;
    }
    struct Node_t* _temp = *head;
    if(_temp->next == NULL)
    {
        *head = NULL;
        free(_temp);
        return;
    }
    while(_temp->next->next!=NULL)
    {
        _temp = _temp->next;
    }
    struct Node_t* last = _temp->next;
    _temp->next = NULL;
    free(last);
    return;
}

void erase(struct Node_t** head, int pos)
{
    int n = size(*head);
    if(pos < 0 || pos > n)
    {
        return;
    }
    if(pos == 0)
    {
        popFront(head);
        return;
    }
    struct Node_t* _temp = *head;
    for(int i = 0; i< pos-1; i++)
    {
        _temp = _temp->next;
    }
    //_temp = pos-1
    struct Node_t* newnode = _temp->next;   //pos
    _temp->next = newnode->next;
    free(newnode);
}