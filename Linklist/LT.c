#include <stdio.h>
#include "list.h"
int main()
{
    typedef struct Node_t node;
    node* head = NULL;
    struct func f =
    {
        .print_node = printNode,
        .pop_Back = popBack,
        .pop_Front = popFront,
    };
    
    head = create_node(1);
    f.push_Back(&head, 101);
    pushBack(&head, 101);
    pushBack(&head, 101);
    pushBack(&head, 10);
    insert(&head, 100, 3);
    // insert(&head, 100, 0);
    // insert(&head, 4, 2);
    
    // popFront(&head);
    // removeHead(&head);
    // popBack(&head);
    erase(&head, 0);
    erase(&head, 4);
    f.print_node(head);
    return 0;
}