#include <stdio.h>
#include <string.h>

void replace_space(char s[], int index)
{
    for(int i = index; i < strlen(s); i++)
    {
        s[i] = s[i+1];
    }
}
int main()
{
    char* p_str = "Hello";
    char p_str2[] = "na khung";
    p_str2[0] = 'N';
    p_str2[1] = 'a';
    p_str2[2] = 'a';
    p_str2[3] = '\0';
    printf("string p_str2: %s\n", p_str2);
    printf("len p_str2: %d\n", strlen(p_str2));


    // strcmp: (so sanh do lon str1 str2)
    //syntas: int strcmp(const char* str1, const char* str2)
    char str1[]= "hello";
    char str2[]= "Hello";
    int res = strcmp(str1, str2);
    // return 1, 0 or -1

    printf("res_strcmp: %d\n", res);


    // strcpy: copy src->destination
    // syntas: char* strcpy(char* destination, char* src)
    char str3[] = "hello";
    char* str4 = " na khung";
    strcpy(&str3[5], str4);
    printf("str_strcpy: %s\n", str3);


    // strcat: cat src->destination
    // syntas: char* strcat(char* destination, char* src)
    char str5[] = "hello";
    char* str6 = " na khung";
    strcat(str5, str6);
    printf("str_strcat: %s\n", str5);

    // strstr: find sub string in main string
    // syntas: char* strstr(char* destination, char* src)
    // return index src in dest or NULL
    char str7[] = "Na bi khung khung";
    char* pt;
    pt = strstr(str7, "N");
    // printf("pt: %f\n", pt);    //address of pt
    while(pt)
    {
        printf("index: %d\n", pt - str7);
        pt = strstr(pt+1, "k");
        if(pt == NULL)
        {
            printf("Find done\n");
        }
    }


    char str8[] = "Na  bi khung";
    char* p_str8;
    p_str8 = strstr(str8, " ");
    while(p_str8)
    {
        printf("index khoang trang: %d\n", p_str8 - str8);
        str8[p_str8 - str8] = 127;
        p_str8 = strstr(p_str8+1, " ");
    }
    printf("chuoi bo khoang trang str8: %s\n", str8);
    // printf("chieu dai chuoi: %d\n", strlen(str8));


    char str9[] = "Na bi khung";
    char* find = strstr(str9, " ");
    while(find)
    {
        int index = find - str9;
        replace_space(str9, index);
        find = strstr(str9, " ");
    }
    printf("chuoi bo khoang trang str9: %s\n", str9);


    // strtok(char* str, "ki tu")
    char str10[] = "01/05/21-2-54-1";
    char* str_tok = strtok(str10, "/-");
    while(str_tok)
    {
        printf("str_tok: %s\n",str_tok);
        str_tok = strtok(NULL, "/-");
    }


    //sprintf
    int day = 10;
    int month = 8;
    int year = 2003;
    char str_sprintf[20];
    sprintf(str_sprintf, "%02d/%d/%04d", day, month, year);
    printf("sprintf: %s\n ", str_sprintf);
    
    return 0;
}