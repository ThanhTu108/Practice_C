#include <stdio.h>

struct Node_t
{
    int data;
    struct Node_t* next;
};


struct Node_t* create_node(int data)
{
    struct Node_t* newnode;
    newnode = malloc(sizeof(struct Node_t));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(struct Node_t** head, int data)
{
    struct Node_t* _newnode = create_node(data);
    _newnode->next = (*head);
    *head = _newnode;
}

void pop(struct Node_t** head)
{
    if(*head == NULL)
    {
        return;
    }
    struct Node_t* _temp = *head;
    *head = (*head)->next;
    free(_temp); 
}

int top(struct Node_t* head)
{
    return head->data;
}

int size(struct Node_t* head)
{
    int cnt = 0;
    while(head !=NULL)
    {
        head = head->next;
        ++cnt;
    }
    return cnt;
}

int main()
{
    typedef struct Node_t node;
    node* st = NULL;

    while (1)
    {
        printf("................\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Size\n");
        printf("0. Exit\n");
        printf("Choose: ");

        int choose;
        scanf("%d", &choose);

        switch (choose)
        {
            case 1: {
                int x;
                printf("Data: ");
                scanf("%d", &x);
                push(&st, x);
                break;
            }
            case 2:
                pop(&st);
                break;
            case 3:
                printf("Top: %d\n", top(st));
                break;
            case 4:
                printf("Size: %d\n", size(st));
                break;
            case 0:
                return 0;
            default:
                printf("Invalid!\n");
                break;
        }
    }
    return 0;
}