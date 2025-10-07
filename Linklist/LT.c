#include <stdio.h>
#include "list.h"
int main()
{
    typedef struct Node_t node;
    node* head = NULL;
    struct func f =
    {
        .print_node = printNode,
    };
    
    head = create_node(1);
    pushBack(&head, 101);
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