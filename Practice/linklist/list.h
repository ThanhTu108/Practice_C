#ifndef __LIST_H
#define __LIST_H

struct list_t 
{
    int data; 
    struct list_t* next;
};
void print_list(struct list_t* head);
struct list_t* create_node_of_list(int data);
void pust_front(struct list_t** head, int data);
void pust_back(struct list_t** head, int data);
#endif