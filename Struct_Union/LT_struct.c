#include <stdio.h>
#include <string.h>
typedef struct 
{
    char name[30];
    int class;
    char student_id[10];
} student_t; 
//value use: '.'
//pointer use:  '->'

void student_get_1(student_t* sv)
{
    printf("Name: ");
    fgets((sv->name), sizeof(sv->name), stdin);
    char* pos;
    if ((pos = strchr(sv->name, '\n')) != NULL)
    {
        *pos = '\0';  //replace /n -> null
    }
    printf("Class: ");
    scanf("%d", &sv->class);
    fflush(stdin);
    printf("Student id: ");
    fgets((sv->student_id), sizeof(sv->student_id), stdin);

}
void print_student_1(student_t sv)
{
    printf("Name: %s - Class: %d - Id: %s \n", sv.name, sv.class, sv.student_id);
}


void student_get_all_1(student_t* sv, int* num)
{
    printf("Enter number: ");
    scanf("%d", num);
    fflush(stdin);
    for(int i = 0; i < *num; i++)
    {
        char* pos;
        printf("Name[%d]: ", i);
        fgets((sv+i)->name, sizeof((sv+i)->name), stdin);
        if((pos = strchr((sv+i)->name, '\n')) != NULL)
        {
            *pos = '\0';
        }
        printf("Class: ");
        scanf("%d", &((sv+i)->class));
        fflush(stdin);
        printf("ID: ");
        fgets((sv+i)->student_id, sizeof((sv+i)->student_id), stdin);
        if((pos = strchr((sv+i)->student_id, '\n')) != NULL)
        {
            *pos = '\0';
        }
    }
}

void student_get_all_2(student_t* sv, int*num)
{
    printf("Enter number: ");
    scanf("%d", num);
    fflush(stdin);
    for(int i = 0; i < *num; i++)
    {
        student_get_1(sv+i);
    }
}

void print_student_all(student_t* sv, int num)
{
    for(int i = 0; i< num; i++)
    {
        printf("Name: %s - Class: %d - Id: %s \n", sv[i].name, sv[i].class, sv[i].student_id);
    }
}
int main()
{
    student_t sv[100];
    int num = 1;
    student_get_all_2(sv, &num);
    print_student_all(sv, num);
    return 0;
}