#include <stdio.h>
#include <stdlib.h>
void capphat_1(int** pt)
{
    *pt = (int*)malloc(10 * sizeof(int));
}

int* capphat_2(int* pt, int n)
{
    pt = (int*)malloc(n * sizeof(int));
    return pt;
}

void capphat_3(int* pt, int n)
{
    int** _p = pt;
    *_p = malloc(n * sizeof(int));
}
int main()
{
    int* pt_1 = NULL;
    capphat_1(&pt_1);
    pt_1[0] = 1;
    printf("%d\n", pt_1[0]);


    int* pt_2 = NULL;
    pt_2 = capphat_2(&pt_2, 3);
    printf("address: %p\n",pt_2);


    int* pt_3 = NULL;
    capphat_3(&pt_3, 3);
    pt_3[0] = 10;
    printf("pt_3[0]: %d\n",pt_3[0]);
    return 0;
}