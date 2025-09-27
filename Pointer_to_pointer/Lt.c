#include <stdio.h>

int arr1[] = {1,2,3,4,5};
int arr2[] = {11,12,13,14,15};
int arr3[] = {21,22,23,24,25};

void ptp()
{
    int x = 100;
    int* pt = &x;
    int** ptt = &pt;
    printf("&x: %d\n", &x);

    printf("pt: %d\n", pt);
    printf("*pt: %d\n", *pt);
    printf("&pt: %d\n", &pt);

    printf("ptt: %d\n", ptt);   //ptt = &pt 
    printf("*ptt: %d\n", *ptt); //*ptt = pt
    printf("**ptt: %d\n", **ptt);   //**ptt = *pt = x
}

void arr_print(int* pt, int num)
{
    for(int i = 0; i<num; i++)
    {
        printf("%d \t", *(pt+i));
    }
    printf("\n");
}
int main()
{
    // ptp();
    int* pt[3];
    pt[0] = arr1;
    pt[1] = arr2;
    pt[2] = arr3;
    
    for(int i = 0; i < 3; i++)
    {
        arr_print(*(pt+i), 5);  //(pt+i) -> int** -> *(pt+i) = pt[i]
    }

    arr_print(pt[0], 5);
    return 0;
}