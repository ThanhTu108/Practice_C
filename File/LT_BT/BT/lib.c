#include <stdio.h>
#include "lib.h"
#include <stdlib.h>
#include <string.h>


struct Info_t* std_get(struct Info_t* sv, int* num)
{
    typedef struct Info_t inf;
    inf* tmp = (inf*)realloc(sv, ((*num)+1) * sizeof(inf));
    if(!tmp)
    {
        printf("can not allocate memory");
        return sv;
    }
    sv = tmp;
    printf("Enter id student: ");
    sv[*num].STT = *num + 1;
    scanf("%d", &sv[*num].id_std);
    fflush(stdin);
    
    printf("Enter name: ");
    gets(sv[*num].name);

    printf("Enter Age: ");
    scanf("%d", &(sv[*num].age));

    printf("Enter Sex: ");
    scanf("%s", &(sv[*num].sex));
    // fflush(stdin);

    printf("Enter Math: ");
    scanf("%f", &(sv[*num].math));

    printf("Enter Phys: ");
    scanf("%f", &(sv[*num].phys));

    printf("Enter Chem: ");
    scanf("%f", &(sv[*num].chem));
    (sv[*num].avr) = ((sv[*num].math) + (sv[*num].phys) + (sv[*num].chem)) / 3.0;
    (*num)++;
    return sv;
}

void std_print(struct Info_t* sv, int num)
{
    printf("%-6s %-10s %-20s %-10s %-10s %-8s %-8s %-8s %-8s\n","STT", "Id", "Name", "Age","Sex", "Math", "Phys", "Chem", "AVR");
    for(int i = 0; i< num; i++)
    {
        printf("%-6d %-10d %-20s %-10d %-10s %-8.02f %-8.02f %-8.02f %-8.02f\n",sv[i].STT ,sv[i].id_std, sv[i].name, sv[i].age, sv[i].sex, sv[i].math, sv[i].phys, sv[i].chem, sv[i].avr);
    }
}
void swap(struct Info_t* a, struct Info_t* b)
{
    struct Info_t temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
void std_sort_avr(struct Info_t* sv, int num)
{
    for(int i = 0; i<num; i++)
    {
        for(int j = 0; j<num -i - 1; j++)
        {
            if(sv[j].avr < sv[j+1].avr)
            {
                swap(&sv[j], (sv+j+1));
            }
        }
    }
}
int cmp_name(const void* ptr1, const void* ptr2)
{
    struct Info_t* sv1 = (struct Info_t*)ptr1;
    struct Info_t* sv2 = (struct Info_t*)ptr2;

    char name1[100], name2[100];
    strcpy(name1, sv1->name);
    strcpy(name2, sv2->name);
    char* token1 = strtok(name1, " ");
    char* last1 = token1;
    while (token1 != NULL) 
    {
        last1 = token1;
        token1 = strtok(NULL, " ");
    }

    char* token2 = strtok(name2, " ");
    char* last2 = token2;
    while (token2 != NULL) 
    {
        last2 = token2;
        token2 = strtok(NULL, " ");
    }

    return strcmp(last1, last2);
}

void std_sort_name(struct Info_t* sv, int num)
{
    qsort(sv, num, sizeof(struct Info_t), cmp_name);
}


struct Info_t* read_file(const char* path, struct Info_t* sv, int* num)
{
    typedef struct Info_t inf;
    inf temp;   
    FILE* f = fopen(path, "r");
    if(!f)
    {
        printf("Can not allocate memory!!!\n");
        return NULL;
    }
    char line[256];
    fgets(line, sizeof(line), f);
    while(!feof(f))
    {
        if (fscanf(f, "%d%d", &temp.STT, &temp.id_std) != 2) 
            break;
        char word[30];
        temp.name[0] = '\0';
        while(fscanf(f, "%s", word)!=0)
        {
            int n;
            if(sscanf(word, "%d", &n)!=0) 
            {
                temp.age = n;
                break;
            }
            if(temp.name[0]!='\0') 
            {
                strcat(temp.name, " ");
            }
            strcat(temp.name, word);
        }
        fscanf(f, "%s %f %f %f %f", temp.sex, &temp.math, &temp.phys, &temp.chem, &temp.avr);
        inf* tmp = realloc(sv, (*num + 1) * sizeof(inf));
        if(!tmp)
        {
            printf("Cannot re-allocate memory");
            return sv;
        }
        sv = tmp;
        sv[*num] = temp;
        (*num)++;
    }   
    fclose(f);
    return sv;
}

void write_file(const char* path, struct Info_t* sv,int start_idx , int num)
{
    FILE* f = fopen(path, "a");
    if(!f)
    {
        printf("Can not open file to write\n");
        return;
    }

    for(int i = start_idx; i < num; i++)
    {
        fprintf(f, "%-6d %-10d %-20s %-10d %-10s %-8.02f %-8.02f %-8.02f %-8.02f\n",
            sv[i].STT ,sv[i].id_std, sv[i].name, sv[i].age, sv[i].sex, sv[i].math, sv[i].phys, sv[i].chem, sv[i].avr);
    }
    fclose(f);
}
