#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k, int n) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    k = k % n;
    if (k == 0)
        return head;

    struct Node* temp = head;
    int count = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    temp->next = head;

    int steps = n - k;
    temp = head;

    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}

int main() {
    int n, k, value;
    struct Node *head = NULL, *temp = NULL, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k, n);

    printf("Rotated List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}