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

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* s1[MAX]; // left to right
    struct Node* s2[MAX]; // right to left

    int top1 = -1, top2 = -1;

    // push root to s1
    s1[++top1] = root;

    printf("Zigzag Traversal: ");

    while (top1 >= 0 || top2 >= 0) {

        // Process s1 (L → R)
        while (top1 >= 0) {
            struct Node* temp = s1[top1--];
            printf("%d ", temp->data);

            // push left then right into s2
            if (temp->left)
                s2[++top2] = temp->left;
            if (temp->right)
                s2[++top2] = temp->right;
        }

        // Process s2 (R → L)
        while (top2 >= 0) {
            struct Node* temp = s2[top2--];
            printf("%d ", temp->data);

            // push right then left into s1
            if (temp->right)
                s1[++top1] = temp->right;
            if (temp->left)
                s1[++top1] = temp->left;
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

    zigzagTraversal(root);

    return 0;
}