/*
    Write function to alow get in4 personal, print in4 using dynamic memory allocatation
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char* name;
    int age;
} info_t;



int main()
{
    info_t sv1;
    // sv1.name = calloc(30, sizeof(char));
    printf("Enter name: ");
    gets(sv1.name);
    printf("Age: ");
    scanf("%d", &sv1.age);


    printf("Name: %s", sv1.name);
    
    return 0;
}