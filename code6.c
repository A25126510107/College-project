#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

struct Node *createNode(char page[])
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertPage(char page[])
{
    struct Node *newNode = createNode(page);

    if (head == NULL)
    {
        head = newNode;
        current = newNode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        current = newNode;
    }

    printf("Page inserted: %s\n", page);
}

void moveForward()
{
    if (current == NULL)
        printf("No pages available\n");
    else if (current->next == NULL)
        printf("Already at the last page\n");
    else
    {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}

void moveBackward()
{
    if (current == NULL)
        printf("No pages available\n");
    else if (current->prev == NULL)
        printf("Already at the first page\n");
    else
    {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}

void deletePage(char page[])
{
    struct Node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Page not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp)
    {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);

    printf("Page deleted\n");
}

void displayForward()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("No pages available\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%s\n", temp->page);
        temp = temp->next;
    }
}

void displayBackward()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("No pages available\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        printf("%s\n", temp->page);
        temp = temp->prev;
    }
}

int main()
{
    int choice;
    char page[50];

    while (1)
    {
        printf("\n1.Insert Page  2.Forward  3.Backward  4.Delete Page  5.Display First-Last  6.Display Last-First  7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter page: ");
                scanf("%s", page);
                insertPage(page);
                break;

            case 2:
                moveForward();
                break;

            case 3:
                moveBackward();
                break;

            case 4:
                printf("Enter page to delete: ");
                scanf("%s", page);
                deletePage(page);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}