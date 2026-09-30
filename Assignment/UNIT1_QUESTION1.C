#include <stdio.h>
#include <stdlib.h>

int i = 0;
int *id = NULL;

void sort();
void search(int value);
void display();

void Insertion(int value)
{
    id = (int *)realloc(id, (i + 1) * sizeof(int));

    id[i] = value;
    i++;

    sort();
}

void sort()
{
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = 0; k < i - 1 - j; k++)
        {
            if (id[k] > id[k + 1])
            {
                int temp = id[k];
                id[k] = id[k + 1];
                id[k + 1] = temp;
            }
        }
    }
}

void search(int value)
{
    int low = 0;
    int high = i - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (id[mid] == value)
        {
            printf("ID found\n");
            return;
        }
        else if (value < id[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("ID not found\n");
}

void display()
{
    for (int j = 0; j < i; j++)
    {
        printf("%d ", id[j]);
    }
    printf("\n");
}

int main()
{
    int choice, n, m;
    while(1)
    {
    printf("Enter 1-Insertion 2-Search 3-Display 4-Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the new ID: ");
            scanf("%d", &n);
            Insertion(n);
            break;

        case 2:
            printf("Enter the ID you want: ");
            scanf("%d", &m);
            search(m);
            break;

        case 3:
            display();
            break;

        case 4:
        free(id);
            exit(0);
    }

}
    return 0;
}