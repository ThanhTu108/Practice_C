#include <stdio.h>
#include <string.h>
void str_get(char* pt, int size)
{
    printf("Enter string: ");
    fgets(pt, size, stdin);
    pt[strlen(pt) - 1] = '\0';
}
void str_rmv_target(char* pt, char* target)
{
    printf("Enter terget: ");
    scanf("%c", target);
    int temp = 0;
    for(int i = 0; pt[i] != '\0'; i++)
    {
        if(*(pt+i) != *target)
        {
            pt[temp++] = pt[i];
        }
    }
    pt[temp] = '\0';
}
void str_reverse(char* pt)
{
    int left = 0;
    int right = strlen(pt) - 1;
    while(left < right)
    {
        int temp = pt[left];
        pt[left] = pt[right];
        pt[right] = temp;
        left++;
        right--;
    }
}

int main()
{
    char c[100];
    char a;
    str_get(c, 100);
    str_rmv_target(c, &a);
    str_reverse(c);
    printf("%s", c);
    return 0;
}