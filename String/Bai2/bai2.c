#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{   
    char* str;
    char* index;
    char find[2];
    int max_len = 256;
    str = (char* )malloc(sizeof(char) * max_len);
    if (str == NULL) {
        printf("Can't not allocate memory!\n");
        return -1;
    }

    printf("Nhap chuoi: ");
    if (fgets(str, max_len, stdin) == NULL) {
        printf("ERR !\n");
        free(str);
        return -1;
    }

    printf("Nhap ki tu can tim: ");
    scanf("%s", &find[0]);
    find[1] = '\0';

    printf("chuoi da nhap la: %s\n", str);
    printf("kich thuoc da nhap la: %d\n", strlen(str));
    index = strstr(str, find);
    while(index)
    {
        printf("index can tim la: %d\n", index - str);
        index = strstr(index + 1, find);
    }

    free(str);
    return 0;
}