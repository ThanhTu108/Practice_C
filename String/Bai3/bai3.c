#include<stdio.h>
#include<string.h>

//strtok
int main()
{

    // Using strtok
    char str[] = "10/08/2003";
    int number[10];
    int i=0;
    char* str_tok = strtok(str, "/");

    while(str_tok)
    {
        number[i++] = atoi(str_tok);
        str_tok = strtok(NULL, "/");
    }
    printf("%d, %d, %d \n",number[0], number[1], number[2]);


    // Using sscanf

    char str_2[] = "10/08/2003";
    int day, month, year;
    sscanf(str_2, "%d/%d/%d", &day, &month, &year);
    printf("Day: %d Month: %d Year: %d", day, month, year);
    return 0;
}