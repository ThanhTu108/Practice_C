#include <stdio.h>
#include "lib.h"
#include <stdlib.h>


int main()
{
    const char* path = "D:\\Desktop\\hoc\\Tu\\Training_lab\\Practice_c\\File\\LT_BT\\BT\\Sv.txt";
    int num = 0;
    struct Func f = 
    {
        .get = std_get,
        .print = std_print,
        .sort_avr = std_sort_avr,
        .sort_name = std_sort_name,
        .read_file = read_file,
        .write_file = write_file,
    };
    struct Info_t* sv = NULL;
    sv = f.read_file(path, sv, &num);
    if (sv == NULL || num == 0) 
    {
        printf("File empty\n");
    } 
    else 
    {
        f.print(sv, num);
    }
    int start_idx = num;
    int choose;
    while (1) 
    {
        printf("\n========== MENU ==========\n");
        printf("1. Get students\n");
        printf("2. Print students\n");
        printf("3. Sort name\n");
        printf("4. Sort array\n");
        printf("5. Save file\n");
        printf("6. Read file\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choose);

        switch (choose) 
        {
            case 1:
                sv = f.get(sv, &num);
                break;
            case 2:
                f.print(sv, num);
                break;
            case 3:
                f.sort_name(sv, num);
                f.print(sv, num);
                printf("Name Sort done\n");
                break;
            case 4:
                f.sort_avr(sv, num);
                f.print(sv, num);
                printf("Avr Sort done\n");
                break;
            case 5:
                f.write_file(path, sv, start_idx, num);
                printf("Save file done!!!\n");
                start_idx = num;
                break;
            case 6:
                if (sv == NULL || num == 0) 
                {
                    printf("File empty\n");
                } 
                else 
                {
                    f.print(sv, num);
                }
                break;
            case 0:
                printf("Exit\n");
                free(sv);
                return 0;
            default:
                printf("Error\n");
        }
    }

   
    
    free(sv);
    return 0;
}
