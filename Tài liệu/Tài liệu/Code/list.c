#include <stdio.h>
#include "list.h"

static Node_t * creatNode(int data)
{
    Node_t *temp = (Node_t *)malloc(1*sizeof(Node_t));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// B-> A
void pushHead(Node_t **head, int data)
{
    Node_t *_temp = creatNode(data);
    if(*head == NULL){
        *head = _temp;
    }
    else{
        _temp->next = *head;
        *head = _temp;
    }
}

// pos đếm từ 0
bool pushAt(Node_t *head, int data, int pos)
{
    int i = 0;
    Node_t *pt = head;
    while (pt != NULL && i != pos-1){
        pt = pt->next;
        i++;
    }

    if(i != pos-1){
        return false;
    }
    else{
        Node_t *temp = creatNode(data);
        temp->next = pt->next;
        pt->next = temp;
    }
    return true;
}

void pushTail(Node_t *head, int data)
{
    Node_t *pt = head;
    while(pt->next != NULL){
        pt = pt->next;
    }
    Node_t *temp = creatNode(data);
    pt->next = temp;
}

void removeHead(Node_t **head)
{
    Node_t *newHead = (*head)->next;
    free(*head);
    *head = newHead;
}

void removeTail(Node_t *head)
{
    Node_t *pt = head;
    while(pt->next->next != NULL)
    {
        pt = pt->next;
    }
    free(pt->next);
    pt->next = NULL;
}

void removeAt(Node_t *head, int pos)
{
    Node_t *pt = head;
    int k = 0;
    while(pt != NULL && k != pos - 1)
    {
        pt = pt->next;
        k++;
    }

    if(k != pos - 1)
    {
        return;
    }
    else{
        Node_t * nodetoDel = pt->next;
        pt->next = pt->next->next;
        free(nodetoDel);
    }
}
