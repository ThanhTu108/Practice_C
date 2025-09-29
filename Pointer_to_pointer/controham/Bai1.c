#include <stdio.h>
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
    *pt = (int**) malloc(*num * sizeof((int*)));
    for(int i = 0; i< *num; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &pt[i]);
    }
}

void arr_print(int* pt, int num)
{
    for(int i = 0; i< num; i++)
    {
        printf("%-5d", *(pt+i));
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
            if(*(pt+j) < pt[j+1])
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
            if(*(pt+j) > pt[j+1])
            {
                swap((pt+j), &pt[j+1]);
            }
        }
    }
}
int main()
{
    int* arr = (int*)malloc()
    return 0;
}