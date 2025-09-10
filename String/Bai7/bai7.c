#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 256
char* enter_name()
{
    char* name;
    name = (char*)malloc(sizeof(char) * MAX_LEN);
    if(!name)
    {
        printf("Can not allocate memory \n");
        free(name);
    }
    printf("Enter name: ");
    fgets(name, MAX_LEN, stdin);
    return name;
}  

void enter_name_array(char* arr[], int* number_of_name)
{
    for(int i = 0; i< *number_of_name; i++)
    {
        arr[i] = enter_name();
        // printf("arr[%d]: %s", i, arr[i]);
    }
}
void swap(char** a, char** b)
{
    char* temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
}
void a_z_name(char* arr[], int number_of_name)
{
    for (int i = 0; i<number_of_name; i++)
    {
        for (int j = 0; j < number_of_name - i - 1; j++)
        {
            if (strcmp(arr[j], arr[j+1]) > 0)
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void print_arr(char* arr[], int number_of_name)
{
    printf("...............\n");
    for (int i = 0; i < number_of_name; i++)
    {
        printf("Name_id[%d]: %s", i, arr[i]);
    }
}

int main()
{
    char* arr[100];
    int n = 5;
    // char* name = enter_name();
    enter_name_array(arr, &n);
    a_z_name(arr, n);
    print_arr(arr, n);
    return 0;
}