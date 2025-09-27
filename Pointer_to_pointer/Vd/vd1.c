#include <stdio.h>

char* s1 = "Chuoi 1";
char* s2 = "Chuoi 2";

void change_string_c1(char** pt)
{
    *pt = s2;
}

char* change_string_c2(char* pt)
{
    pt = s2;
    return pt;
}

void change_string_c3(char* pt)
{
    char** _p = pt;
    *_p = s2;
}

int main()
{
    char* s3 = s1;
    printf("S3: %s\n", s3);
    change_string_c1(&s3);
    printf("S3: %s\n", s3);

    printf("...............\n");

    char* s3_2 = s1;
    printf("S3_2: %s\n", s3_2);
    s3_2 = change_string_c2(s3_2);
    printf("S3_2: %s\n", s3_2);

    printf("...............\n");
    char* s3_3 = s1;
    printf("S3_3: %s\n", s3_3);
    change_string_c3(&s3_3);
    printf("S3_3: %s\n", s3_3);
    return 0;
}