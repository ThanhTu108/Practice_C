#include <stdio.h>
#include <string.h>

int main()
{
    char str[100] = {0};
    fgets(str, sizeof(str), stdin);
    int l = 0;
    int r = strlen(str) - 1;
    while(l < r)
    {
        char temp;
        temp = str[l];
        str[l] = str[r];
        str[r] = temp;
        l++;
        r--;
    }
    printf("%s\n", str);
    return 0;
}