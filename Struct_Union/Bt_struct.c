#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[30];
    float avr;
    int age;
    int math, phys, chem;
    char sex[3];
    char rank[10];
} Student_t;

void Student_get(Student_t* pt, int* num)
{
    printf("Enter number: ");
    scanf("%d", num);
    fflush(stdin);
    for(int i = 0; i < *num; i++)
    {
        // char* pos;
        printf("Name: ");
        gets(pt[i].name);
        printf("Sex: ");
        gets(pt[i].sex);

        printf("Age: ");
        scanf("%d", &pt[i].age);  
        printf("Math: ");
        scanf("%d", &pt[i].math);   
        printf("Phys: ");
        scanf("%d", &pt[i].phys);   
        printf("Chemi: ");
        scanf("%d", &pt[i].chem);  
        fflush(stdin); 
        pt[i].avr = (pt[i].math + pt[i].phys + pt[i].chem)/3;
    }
}
void student_rank(Student_t* pt, int num)
{
    for(int i = 0; i< num; i++)
    {
        if(pt[i].avr >= 8.0)
        {
            strcpy((pt+i)->rank, "excellent");
        }
        else if(pt[i].avr >= 6.5)
        {
            strcpy((pt+i)->rank, "good");
        }
        else
        {
            strcpy((pt+i)->rank, "not good");
        }
    }
}
void student_print(Student_t* pt, int num)
{
    printf("%-10s %-5s %-7s %-5s %-5s %-5s %-5s %-6s\n", "Name", "Sex", "Age", "Math", "Phys", "Chemistry", "Average", "degree");
    for(int i = 0 ;i<num; i++)
    {
        printf("%-10s %-5s %-7d %-5d %-5d %-5d %-5f %-6s\n", pt[i].name,
            pt[i].sex, pt[i].age, pt[i].math, (pt+i)->phys, (pt+i)->chem, (pt+i)->avr, (pt+i)->rank);
    }
}
void swap(Student_t* a, Student_t* b)
{
    Student_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void student_sort_by_avr(const Student_t* pt, int num)
{
    //Keep pt old
    Student_t sv_copy[100];
    memcpy(sv_copy, pt, num * sizeof(Student_t));
    
    for(int i =0 ;i<num; i++)
    {
        for(int j = 0 ;j < num-i-1; j++)
        {
            if((pt+j)->avr < pt[j+1].avr)
            {
                swap((pt+j), &pt[j+1]);
            }
        }
    }
    student_rank(sv_copy, num);
    student_print(sv_copy, num);
}



int main()
{
    Student_t sv[100];
    int num;
    Student_get(sv, &num);
    // student_print(sv, num);

    student_sort_by_avr(sv, num);
    return 0;
}