#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(int value)
{
    struct Node *newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    printf("Roll number %d inserted at beginning\n", value);
}

void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Roll number %d inserted at end\n", value);
}

void searchValue(int value)
{
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Roll number %d found at position %d\n", value, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Roll number %d is not available\n", value);
}

void deleteValue(int value)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Roll number %d is not available\n", value);
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Roll number %d deleted\n", value);
}

void displayList()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1.Insert Beginning  2.Insert End  3.Search  4.Delete  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                displayList();
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &value);
                insertAtEnd(value);
                displayList();
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &value);
                searchValue(value);
                displayList();
                break;

            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                displayList();
                break;

            case 5:
                displayList();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}