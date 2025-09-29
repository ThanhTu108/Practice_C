#include <stdio.h>
#include <stdlib.h>

typedef void (*Getfunc_t)(int**, int*);
typedef void (*Activefunc_t)(int*, int);

typedef struct 
{
    Getfunc_t get;
    Activefunc_t print;
    Activefunc_t increase;
    Activefunc_t decrease;
} Func_t;

void arr_get(int** pt, int* num)
{
    printf("enter num: ");
    scanf("%d", num);
    *pt = (int*)malloc(*num * sizeof(int));
    for(int i = 0; i< *num; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &(*pt)[i]);
        // scanf("%d", (*pt+i));
    }
}

void arr_print(int* pt, int num)
{
    for(int i = 0; i< num; i++)
    {
        printf("%-5d", pt[i]);
    }
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void arr_increase(int* pt, int num)
{
    for(int i = 0; i<num; i++)
    {
        for(int j = 0; j<num-i-1; j++)
        {
            if(*(pt+j) > pt[j+1])
            {
                swap((pt+j), &pt[j+1]);
            }
        }
    }
}

void arr_decrease(int* pt, int num)
{
    for(int i = 0; i<num; i++)
    {
        for(int j = 0; j<num-i-1; j++)
        {
            if(*(pt+j) < pt[j+1])
            {
                swap((pt+j), &pt[j+1]);
            }
        }
    }
}
int main()
{
    int* arr = NULL;
    int n;
    int choice;
    Func_t func = 
    {
        .get = arr_get,
        .print = arr_print,
        .increase = arr_increase,
        .decrease = arr_decrease,
    };
    while(1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Enter array\n");
        printf("2. Print array\n");
        printf("3. Increase\n");
        printf("4. Decrease\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (arr != NULL) {
                free(arr);
                arr = NULL;
            }
            func.get(&arr, &n);
            break;
        case 2:
            if (arr != NULL)
                func.print(arr, n);
            else
                printf("Arr Null!\n");
            break;
        case 3:
            if (arr != NULL)
                func.increase(arr, n);
            else
                printf("Arr Null!\n");
            break;
        case 4:
            if (arr != NULL)
                func.decrease(arr, n);
            else
                printf("Arr Null!\n");
            break;
        case 5:
            free(arr);
            return 0;
        default:
            printf("Lựa chọn không hợp lệ!\n");
        }
    }
    return 0;
}