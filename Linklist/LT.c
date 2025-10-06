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
    pushFront(&head, 2);
    push_at(head, 3, 2);
    push_at(head, 4, 2);
    pushBack(&head, 101);
    // removeHead(&head);
    f.print_node(head);
    return 0;
}