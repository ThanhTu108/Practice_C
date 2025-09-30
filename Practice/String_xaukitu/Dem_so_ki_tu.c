#include <stdio.h>
//a: 97

//z: 122

int main()
{
    char c[1000];
    gets(c);
    int fre_char[26]= {0};
    for(int i = 0; c[i]!='\0'; i++)
    {
        fre_char[*(c+i) - 'a']++;
    }
    for(int i = 0; i<26; i++)
    {
        printf("%c:%d\t",i+'a' ,fre_char[i]);
    }
    return 0;
}