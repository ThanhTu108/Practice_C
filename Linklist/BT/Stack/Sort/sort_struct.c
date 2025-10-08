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
    char token = strtok()
}
void sort_sv_name(node** head)
{

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
    print_node(sv);
    return 0;
}