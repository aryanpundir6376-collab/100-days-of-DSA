#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int empty() {
    return (front == -1);
}

int full() {
    return (rear == MAX - 1);
}

void push_front(int value) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = value;
}

void push_back(int value) {
    if (full()) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}

void pop_front() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }
    printf("Popped from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void pop_back() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }
    printf("Popped from back: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

void get_front() {
    if (empty()) {
        printf("-1\n");
    } else {
        printf("Front element: %d\n", deque[front]);
    }
}

void get_back() {
    if (empty()) {
        printf("-1\n");
    } else {
        printf("Back element: %d\n", deque[rear]);
    }
}

void size() {
    if (empty()) {
        printf("Size: 0\n");
    } else {
        printf("Size: %d\n", rear - front + 1);
    }
}

void clear() {
    front = rear = -1;
    printf("Deque cleared\n");
}

void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
    printf("Deque reversed\n");
}

void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = front; j < rear; j++) {
            if (deque[j] > deque[j + 1]) {
                int temp = deque[j];
                deque[j] = deque[j + 1];
                deque[j + 1] = temp;
            }
        }
    }
    printf("Deque sorted\n");
}

int main() {
    int n, value;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation: ");
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            printf("Enter value: ");
            scanf("%d", &value);
            push_front(value);
        }
        else if (strcmp(op, "push_back") == 0) {
            printf("Enter value: ");
            scanf("%d", &value);
            push_back(value);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            get_front();
        }
        else if (strcmp(op, "back") == 0) {
            get_back();
        }
        else if (strcmp(op, "size") == 0) {
            size();
        }
        else if (strcmp(op, "empty") == 0) {
            printf("Empty: %d\n", empty());
        }
        else if (strcmp(op, "clear") == 0) {
            clear();
        }
        else if (strcmp(op, "reverse") == 0) {
            reverse();
        }
        else if (strcmp(op, "sort") == 0) {
            sort();
        }
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}