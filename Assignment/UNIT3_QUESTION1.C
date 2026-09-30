#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

void create(int roll)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

void insertBeginning(int roll)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int roll)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void search(int roll)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("Roll number %d found\n", roll);
            return;
        }

        temp = temp->next;
    }

    printf("Roll number %d not found\n", roll);
}

void deleteNode(int roll)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Roll number %d not found\n", roll);
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Roll number %d deleted\n", roll);
}

void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Roll numbers: ");

    while (temp != NULL)
    {
        printf("%d ", temp->roll);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    create(101);
    create(102);
    create(103);

    display();

    insertBeginning(100);
    display();

    insertEnd(104);
    display();

    search(102);
    search(110);

    deleteNode(102);
    display();

    deleteNode(110);

    return 0;
}