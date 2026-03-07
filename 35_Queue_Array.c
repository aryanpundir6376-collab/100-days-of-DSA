#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = x;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main()
{
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Queue elements are:\n");
    display();

    return 0;
}