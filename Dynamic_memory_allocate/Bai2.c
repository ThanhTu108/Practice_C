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
    sv = malloc((*num +1) * sizeof(info_t));

    memcpy(sv, pt, sizeof(pt)* (*num));
    sv[*num].name = malloc(sizeof(char));
    sv[*num].sex = malloc(sizeof(char));
    
    printf("Name: ");
    gets(sv[*num].name);
    printf("Age: ");
    scanf("%d", &sv->age);
    fflush(stdin);
    printf("Sex: ");
    gets(sv[*num].sex);
    (*num)++;

    free(pt);
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
    printinfo(sv1, n);
    free(sv1);
    return 0;
}