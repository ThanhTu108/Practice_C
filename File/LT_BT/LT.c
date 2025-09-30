#include <stdio.h>


int main()
{
    FILE* fp;
    fp = fopen("D:\\Desktop\\hoc\\Tu\\Training_lab\\Practice_c\\File\\LT_BT\\output\\text.txt", "a+");
    if(fp!= NULL)
    {
        fprintf(fp, "Date: %02d/%02d/%04d\n", 3,6,2003);
        fclose(fp);
    }

    return 0;
}