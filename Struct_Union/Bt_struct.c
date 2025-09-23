#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[30];
    float avr;
    int age;
    int math, phys, chem;
    char sex[3];
} Student_t;

void Student_get(Student_t* pt, int* num)
{
    printf("Enter number: ");
    scanf("%d", num);
    fflush(stdin);
    for(int i = 0; i < *num; i++)
    {
        char* pos;
        printf("Name: ");
        gets(pt[i].name);
        fflush(stdin);
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
void student_print(Student_t* pt, int num)
{
    printf("%-10s %-5s %-7s %-5s %-5s %-5s %-5s\n", "Name", "Sex", "Age", "Math", "Phys", "Chemistry", "Average");
    for(int i = 0 ;i<num; i++)
    {
        printf("%-10s %-5s %-7d %-5d %-5d %-5d %-5f\n", pt[i].name,
            pt[i].sex, pt[i].age, pt[i].math, (pt+i)->phys, (pt+i)->chem, (pt+i)->avr);
    }
}
int main()
{
    Student_t sv[100];
    int num;
    Student_get(sv, &num);
    student_print(sv, num);
    return 0;
}