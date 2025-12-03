#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

#define MIN_NUM(a, b) ((a < b)? a : b)


int mystrlen(char* c)
{
    int cnt = 0;
    while(c[cnt]!='\0')
    {
        cnt++;
    }
    return cnt;
}

int mystrcmp(const char* a, const char* b)
{
    int n1 = mystrlen(a);
    int n2 = mystrlen(b);
    for(int i = 0; i < MIN_NUM(n1, n2); i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i] > b[i]) return 1;
            else if(a[i] < b[i]) return -1;
        }
    }
    if(n1 == n2)
    {
        return 0;
    }
    else if(n1 > n2) return 1;
    else return -1;
}

void swap_str(char** a, char** b)
{
    char** temp = *a;
    *a = *b;
    *b = temp;
}

int lexicographic_sort(const char* a, const char* b) 
{
    return mystrcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return mystrcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
     
}

int sort_by_length(const char* a, const char* b) {

}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    for(int i = 0; i<len; i ++)
    {
        for(int j = 0; j < len - i- 1; j++)
        {
            if(cmp_func(arr[j], arr[j+1]) > 0)
            {
                swap_str(arr[j], arr[j+1]);
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}