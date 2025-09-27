#include <stdio.h>

// void arr_get(int* pt, int* num)
// {

// }

int main()
{
    int* pt[5];
    pt[0] = malloc(5 * sizeof(int));
    for(int i=0; i < 5; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &pt[0][i]);
    }

    

    for(int i = 0; i < 5 - 1; i++)
    {
        for(int j=0; j<5-1-i; j++)
        if(pt[0][j] < pt[0][j+1])
        {
            int temp = pt[0][j];
            pt[0][j] = pt[0][j+1];
            pt[0][j+1] = temp;
        }
    }

    for (int i = 0; i< 5; i++)
    {
        printf("%d\t", pt[0][i]);
    }
}