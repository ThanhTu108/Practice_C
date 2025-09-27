#include <stdio.h>
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
int main()
{
    ptp();
    return 0;
}