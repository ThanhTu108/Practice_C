#include <stdio.h>

typedef struct {
    char id[10];
    char Name[30];
    int phone_number;
    char sex[3];
    float math;
    float phys;
    float chem;
    float avr;
    char rank[10];
} student_t;
void student_get(student_t* st)
{
    printf("ID_student: ");
    scanf("%s", st->id);
    fflush(stdin);
    printf("Name: ");
    gets(st->Name);
    printf("Sex: ");
    gets(st->sex);
    printf("Phone: ");
    scanf("%d", &st->phone_number);
    printf("Math: ");
    scanf("%f", &(st->math));
    {
        while(st->math < 0 || st->math > 10)
        {
            printf("Math: ");
            scanf("%f", &(st->math));
        }
    }
    printf("Phys: ");
    scanf("%f", &(st->phys));
    {
        while(st->phys < 0 || st->phys > 10)
        {
            printf("Phys: ");
            scanf("%f", &(st->phys));
        }
    }
    printf("Chem: ");
    scanf("%f", &(st->chem));
    {
        while(st->chem < 0 || st->chem > 10)
        {
            printf("Chem: ");
            scanf("%f", &(st->chem));
        }
    }
}
void student_print(student_t* st)
{
    printf("%-15s %-15s %-15s %-4s %-4s %-4s %-4s\n", "Id", "Name", "Phone number", "Math", "Physical", "chem");
    printf("id_student: %s\n", st->id);
    printf("Name: %s\n", st->Name);
    printf("Phone: %d\n", st->phone_number);
    printf("Math: %.2f\n", st->math);
    printf("Math: %.2f\n", st->phys);
    printf("Math: %.2f\n", st->chem);
    printf("Avr: %.2f\n", ((st->chem)+(st->math)+(st->phys))/3.0);
}


int main()
{
    student_t st;
    student_get(&st);
    student_print(&st);
    return 0;
}