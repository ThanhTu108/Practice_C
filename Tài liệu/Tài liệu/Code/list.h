#ifndef __LIST_H
#define __LIST_H
#include <stdbool.h>

typedef struct Node_t{
    int data;
    struct Node_t *next;
}   Node_t;

void pushHead(Node_t **head, int data);
bool pushAt(Node_t *head, int data, int pos);
void pushTail(Node_t *head, int data);
void removeHead(Node_t **head);
void removeTail(Node_t *head);
void removeAt(Node_t *head, int pos);
#endif // __LIB_H


