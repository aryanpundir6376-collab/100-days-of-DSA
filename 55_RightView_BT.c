#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Right View Traversal
void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("Right View: ");

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            // If it's the last node of this level
            if (i == size - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }
    }

    printf("\n");
}

int main() {
    int N;

    printf("Enter number of nodes: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter level-order traversal (-1 for NULL):\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    rightView(root);

    return 0;
}