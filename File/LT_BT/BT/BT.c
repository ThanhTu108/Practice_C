#include <stdio.h>
#include "lib.h"
#include <stdlib.h>


int main()
{
    int num = 0;
    struct Func f = 
    {
        .get = std_get,
        .print = std_print,
        .sort_avr = std_sort_avr,
        .sort_name = std_sort_name,
    };
    struct Info_t* sv = NULL;
    sv = calloc(3 , sizeof(struct Info_t*));
    sv = f.get(sv, &num);
    sv = f.get(sv, &num);
    printf("Danh sách ban đầu:\n");
    f.print(sv, num);

    printf("Sap xep: \n");
    f.sort_name(sv, num);
    f.print(sv, num);
    free(sv);
    return 0;
}
