#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Info_t
{
    char name[60];
    float gpa;
};

struct Node_t
{
    struct Info_t data;
    struct Node_t* next;
};

typedef struct Info_t inf;
typedef struct Node_t node;

node* create_info(inf sv)
{
    node* _newnode = malloc(sizeof(node));
    if(_newnode == NULL)
    {
        printf("Cannot allocate memory!!!");
        return NULL;
    }
    _newnode->data = sv;
    _newnode->next = NULL;
    return _newnode;
};

void pushBack(node** head, inf data)
{
    node* _newnode = create_info(data);
    if(*head == NULL)
    {
        *head = _newnode;
        return;
    }
    node* _temp = *head;
    while(_temp->next !=NULL)
    {
        _temp = _temp->next;
    }
    _temp->next = _newnode;
}

void print_node(node* head)
{
    node* _temp = head;
    while(_temp!=NULL)
    {
        printf("Name: %s\t Gpa: %.2f\n",_temp->data.name, _temp->data.gpa);
        _temp = _temp->next;
    }
}
void swap_name(node* sv1, node* sv2)
{
    char* last1;
    char* last2;
    char name1[50], name2[50];
    strcpy(name1, sv1->data.name);
    strcpy(name2, sv2->data.name);

    char* token1 = strtok(name1, " ");
    while(token1!=NULL)
    {
        last1 = token1;
        token1 = strtok(NULL, " ");
    }

    char* token2 = strtok(name2, " ");
    while(token2!=NULL)
    {
        last2 = token2;
        token2 = strtok(NULL, " ");
    }
    if(strcmp(last1, last2) > 0)
    {
        inf _temp = sv1->data;
        sv1->data = sv2->data;
        sv2->data = _temp;
    }
}
void sort_sv_name(node** head)
{
    for(node* i = *head; i!=NULL; i = i->next)
    {
        for(node* j = *head; j->next!=NULL; j=j->next)
        {
            swap_name(j, j->next);
        }
    }
}
int main()
{
    node* sv = NULL;
    inf sv1 = {"tran le thanh tu", 3.7};
    inf sv2 = {"Tran Thi B", 3.4};
    inf sv3 = {"Le Van C", 3.9};
    pushBack(&sv, sv1);
    pushBack(&sv, sv2);
    pushBack(&sv, sv3);
    sort_sv_name(&sv);
    print_node(sv);
    return 0;
}