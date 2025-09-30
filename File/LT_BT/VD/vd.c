#include <stdio.h>

void f_write(const char* path, char* str)
{
    FILE* fp;
    fp = fopen(path, "a+");
    if(!fp)
    {
        printf("can not open file");
        // return NULL; 
    }
    fprintf(fp, "%s\n", str);
    fclose(fp);
    // return fp;
}

char* f_gets(const char* path, int* offset)
{
    FILE* fp;
    char* pt;
    
    fp = fopen(path, "a+");
    if(!fp)
    {
        printf("can not open file");
        // return NULL; 
    }
    pt = (char*)malloc(ftell(fp) * sizeof(char));

    fseek(fp, *offset, SEEK_SET);
    
    fgets(pt, 100, fp);
    *offset = ftell(fp);
    fclose(fp);
    return pt;
}


int main()
{
    int offset = 0;
    char* path = "D:\\Desktop\\hoc\\Tu\\Training_lab\\Practice_c\\File\\LT_BT\\VD\\VD1.txt";
    char *s = "toi yeu viet nam";
    char *s2 = "thich hoc lap trinh";
    f_write(path, s);
    f_write(path, s2);
    char* res = f_gets(path, &offset);
    printf("%s", res);
    res = f_gets(path, &offset);
    printf("%s", res);
    return 0;
}