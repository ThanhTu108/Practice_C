#ifndef __LIST_H__
#define __LIST_H__
#include <stdbool.h>
#include <stdlib.h>
struct Node_t
{
    int data;
    struct Node_t* next;
};
typedef void(*func_ptr)(struct Node_t*);
struct func
{
    func_ptr print_node;
};

void printNode(struct Node_t* node);
struct Node_t* create_node(int data);

void pushFront(struct Node_t** head, int data);
void insert(struct Node_t** head, int data, int pos);
void pushBack(struct Node_t** head, int data);
void popFront(struct Node_t** head);
void popBack(struct Node_t** head);
void erase(struct Node_t** head, int pos);
void push_at(struct Node_t* head, int data, int pos);

void removeHead(struct Node_t** head);
#endif // __LIST_H__