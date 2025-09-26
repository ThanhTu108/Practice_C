#include <stdio.h>
#include <stdlib.h>
void func_malloc()
{
    int* pt = (int* )malloc(10 * sizeof(int));
    printf("%d\n", pt[0]);
    pt[0] = 100;
    printf("%d\n", pt[0]);
    free(pt);
    printf("%d", pt[0]);
}


void func_calloc()
{
    int* pt = (int* )calloc(10, sizeof(int));
    printf("%d\n", pt[0]);
    pt[0] = 100;
    printf("%d\n", pt[0]);
    free(pt);
    printf("%d", pt[0]);
}

int* arr_get(int* num)
{
    int* pt;
    printf("Enter num: ");
    scanf("%d", num);
    pt = malloc(*num * sizeof(int));
    for(int i = 0; i < *num; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", pt+i);
    }
    return pt;
}

int* arr_add(int* pt, int* num)
{
    int idx, value;
    printf("Enter number what u want: ");
    scanf("%d", &value);
    printf("Enter index what u want: ");
    scanf("%d", &idx);

    int* arr = (int* )malloc((*num) + 1 * sizeof(int));
    memcpy(arr, pt, (*num) * sizeof(int));
    for(int i = *num; i > idx; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[idx] = value;
    (*num)++;
    free(pt);
    return arr;
}

int* arr_remove(int* pt, int* num)
{
    int idx;
    printf("Enter index what u want to remove: ");
    scanf("%d", &idx);
    int* arr = malloc((*num - 1) * sizeof(int));
    memcpy(arr, pt, (*num) * sizeof(int));

    for(int i = idx; i < *num; i++)
    {
        arr[i] = arr[i+1];
    }
    (*num)--;
    free(pt);
    return arr;
}

void arr_print(int* pt, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("%d \t", pt[i]);
    }
    printf("\n");
}


int main()
{
    int* arr;
    int n;
    arr = arr_get(&n);
    arr = arr_add(arr, &n);
    arr_print(arr, n);
    arr = arr_remove(arr, &n);
    arr_print(arr, n);

    free(arr);
    return 0;
}