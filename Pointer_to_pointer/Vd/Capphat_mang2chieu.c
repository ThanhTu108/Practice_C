#include <stdio.h>

void arr_2d_get(int** pt, int row, int col)
{
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &pt[i][j]);
        }
    }
}

void arr_2d_print(int** pt, int row, int col)
{
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%-4d", pt[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row, col;
    printf("row, col: ");
    scanf("%d %d", &row, &col);   

    int** ptt = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i <row; i++)
    {
        ptt[i] = (int*)malloc(col * sizeof(int));
    }
    arr_2d_get(ptt, row, col);
    arr_2d_print(ptt, row, col);
    

    for(int i = 0; i <row; i++)
    {
        free(ptt[i]);
    }
    free(ptt);
    return 0;
}