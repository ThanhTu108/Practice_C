#include <stdio.h>

void arr_2d_get(int** pt, int row, int col)
{
    for(int i = 0; i<row; i++)
    {
        for(int j =0; j<col; j++)
        {
            printf("Arr[%d][%d]: ", i, j);
            scanf("%d", &pt[i][j]);
        }
    }
}

void arr_2d_remove(int** pt, int row, int col)
{
    
}

void arr_2d_print(int** pt, int row, int col)
{
    for(int i = 0; i<row; i++)
    {
        for(int j =0; j<col; j++)
        {
            printf("%-4d", pt[i][j]);
        }
        print("\n");
    }
}

int main()
{
    int row = 5, col = 5;
    int** pt = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i<row; i++)
    {
        *(pt+i) = (int*)malloc(col * sizeof(int));
    }

    arr_2d_get(pt, row, col);
    arr_2d_print(pt, row, col);
    return 0;
}