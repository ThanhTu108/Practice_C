#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max_len = 256;
    char* str;
    char* find;
    char kt[2];
    int count = 0;
    str = (char*) malloc(max_len * sizeof(char));
    if(!str)
    {
        printf("Can't not allocate memory\n");
        return -1;
    }

    printf("Nhap vao chuoi: ");
    fgets(str, max_len, stdin);

    printf("Nhap ki tu: ");
    scanf("%s", &kt[0]);
    kt[1] = '\0';
    find = strstr(str, kt);
    while(find)
    {
        find = strstr(find + 1, kt);
        count++;
    }

    printf("chuoi da nhap: %s", str);
    printf("So ki tu: %d", count);

    free(str);

}