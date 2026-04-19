#include "list.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct list_t* my_list = create_node_of_list(100);
    pust_front(&my_list, 10);
    pust_back(&my_list, 0);
    print_list(my_list);
    return 0;
}