#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    Node* root = newNode(arr[0]);
    Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        Node* curr = queue[front++];

        // Left child
        if (i < n) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
            i++;
        }

        // Right child
        if (i < n) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
            i++;
        }
    }

    return root;
}

// Count nodes
int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isComplete(Node* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check Min Heap property
int isMinHeap(Node* root) {
    if (root == NULL)
        return 1;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Only left child
    if (root->right == NULL)
        return (root->val <= root->left->val) &&
               isMinHeap(root->left);

    // Both children
    return (root->val <= root->left->val &&
            root->val <= root->right->val &&
            isMinHeap(root->left) &&
            isMinHeap(root->right));
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && isMinHeap(root))
        printf("Output: YES\n");
    else
        printf("Output: NO\n");

    return 0;
}