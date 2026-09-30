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

void insertPage(char page[])
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        current = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void moveForward()
{
    if (current == NULL)
    {
        printf("No page available\n");
    }
    else if (current->next == NULL)
    {
        printf("Already at the last page\n");
    }
    else
    {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}

void moveBackward()
{
    if (current == NULL)
    {
        printf("No page available\n");
    }
    else if (current->prev == NULL)
    {
        printf("Already at the first page\n");
    }
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

    if (head == NULL)
    {
        printf("No pages available\n");
        return;
    }

    printf("Pages first to last:\n");

    while (temp != NULL)
    {
        printf("%s\n", temp->page);
        temp = temp->next;
    }
}

void displayBackward()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("No pages available\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Pages last to first:\n");

    while (temp != NULL)
    {
        printf("%s\n", temp->page);
        temp = temp->prev;
    }
}

int main()
{
    insertPage("Google");
    insertPage("YouTube");
    insertPage("GitHub");
    insertPage("ChatGPT");

    displayForward();
    displayBackward();

    printf("\n");

    moveForward();
    moveForward();
    moveBackward();

    deletePage("YouTube");

    printf("\nAfter deletion:\n");

    displayForward();
    displayBackward();

}