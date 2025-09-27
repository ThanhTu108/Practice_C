#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char* name;
    int age;
    char* sex;
} info_t;

info_t* getinfo(info_t* pt, int* num)
{
    info_t* sv;
    sv = malloc((*num+1) * sizeof(info_t));

    memcpy(sv, pt, sizeof(info_t)* (*num));
    sv[*num].name = malloc(100);
    sv[*num].sex = malloc(100);
    
    printf("Name: ");
    gets(sv[*num].name);
    printf("Age: ");
    scanf("%d", &sv[*num].age);
    fflush(stdin);
    printf("Sex: ");
    gets(sv[*num].sex);
    (*num)++;

    free(pt);
    return sv;
}

info_t* deleteInfo(info_t* pt, int* num)
{
    char* target = malloc(100);
    printf("Enter target name: ");
    gets(target);

    for(int  i = 0; i < *num; i++)
    {
        if(strcmp(pt[i].name, target) == 0)
        {
            free(pt[i].name);
            free(pt[i].sex);
            for(int j = i; j<*num - 1; j++)
            {
                pt[j] = pt[j+1];
            }
            (*num)--;
            i--;
        }
    }

    info_t* sv = realloc(pt, (*num)*sizeof(info_t));
    free(target);    
    return sv;
}

void printinfo(info_t* pt, int num)
{
    printf("%-10s %-10s %-3s %-5s\n","STT", "Name", "Age", "Sex");
    for(int i = 0; i< num; i++)
    {
        printf("%-10d %-10s %-3d %-5s",i, pt[i].name, pt[i].age, pt[i].sex);
    }
    printf("\n");
}


int main()
{
    info_t* sv1 = NULL;
    int n = 0;
    sv1 = getinfo(sv1, &n);
    sv1 = getinfo(sv1, &n);
    sv1 = deleteInfo(sv1, &n);
    printinfo(sv1, n);
    free(sv1);
    return 0;
}