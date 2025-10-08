#include <stdio.h>

struct Student
{
    
};

struct Node_t
{
    int data;
    struct Node_t* next;
};

struct Node_t* create_node(int data)
{
    struct Node_t* newnode = malloc(sizeof(struct Node_t));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void pushBack(struct Node_t** head, int data)
{
    struct Node_t* newnode = create_node(data);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct Node_t* _temp = *head;
    while(_temp->next!=NULL)
    {
        _temp = _temp->next;
    }
    _temp->next = newnode;
    return;
}

void print_node(struct Node_t* head)
{
    struct Node_t* _temp = head;
    while(_temp!=NULL)
    {
        printf("%d\t", _temp->data);
        _temp = _temp->next;
    }
}
void swap(struct Node_t* i, struct Node_t* j)
{
    int _temp = i->data;
    i->data = j->data;
    j->data = _temp;
}    
void sort(struct Node_t** head)
{
    for(struct Node_t* i = *head; i!=NULL; i = i->next)
    {
        for(struct Node_t* j = *head; j->next !=NULL; j=j->next)
        {
            if(j->data > (j->next->data))
            {
                swap(j, (j->next));
            }
        }
    }
}

int main()
{
    int a[] = {1,8,3,7,0,2,4,9,6,5};
    struct Node_t* sv = NULL;
    for(int i = 0; i< 10; i++)
    {
        pushBack(&sv, a[i]);
    }
    sort(&sv);
    print_node(sv);
    return 0;
}