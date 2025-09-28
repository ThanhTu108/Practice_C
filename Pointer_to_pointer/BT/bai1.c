#include <stdio.h>
#include <stdlib.h>
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
void arr_2d_remove(int** pt, int* row, int col, int idx)
{
    free(pt[idx]);
    for(int i = idx; i < *row - 1; i++)
    {
        pt[i] = pt[i+1];
    }   
    (*row)--;
}

int** arr_2d_add(int** pt, int* row, int col, int idx)
{
    int** new_arr;
    new_arr = (int**)malloc((*row + 1) * sizeof(int*));
    for(int i = 0; i < *row+1; i++)
    {
        new_arr[i] = (int*)malloc(col * sizeof(int));
    } 
    for(int i = 0; i < idx; i++)
    {
        for(int j = 0; j<col; j++)
        {
            new_arr[i][j] = pt[i][j];
        }
    }
    for(int i=idx; i<*row; i++)
    {   
        for (int j = 0; j < col; j++) {
            new_arr[i+1][j] = pt[i][j];
        }
    }
    for(int i = 0 ;i < col; i++)
    {
        printf("Arr[%d][%d]: ", idx, i);
        scanf("%d", &new_arr[idx][i]);
    }
    (*row) ++ ;

    for (int i = 0; i < *row; i++) {
        free(pt[i]);
    }
    free(pt);
    return new_arr;
}

void arr_2d_print(int** pt, int row, int col)
{
    for(int i = 0; i<row; i++)
    {
        for(int j =0; j<col; j++)
        {
            printf("%-4d", pt[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row = 3, col = 3;
    int** pt = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i<row; i++)
    {
        *(pt+i) = (int*)malloc(col * sizeof(int));
    }

    arr_2d_get(pt, row, col);
    arr_2d_remove(pt, &row, col, 1);
    pt = arr_2d_add(pt, &row, col, 1);
    arr_2d_print(pt, row, col);



    for(int i = 0; i<row; i++)
    {
        free(pt[i]);
    }

    free(pt);
    return 0;
}