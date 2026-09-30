#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;

    printf("%d inserted\n", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    enqueue(60);      

    dequeue();
    dequeue();

    display();

    enqueue(60);      
    enqueue(70);       

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();         

    return 0;
}

