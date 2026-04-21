#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    return root;
}

int main() {
    int N, i, val, n1, n2;
    struct Node* root = NULL;

    // Input with prompts
    printf("Enter number of nodes: ");
    scanf("%d", &N);

    printf("Enter %d values for BST:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter two node values to find LCA: ");
    scanf("%d %d", &n1, &n2);

    // Find LCA
    struct Node* lca = findLCA(root, n1, n2);

    // Output
    if (lca != NULL)
        printf("Lowest Common Ancestor is: %d\n", lca->data);
    else
        printf("LCA not found.\n");

    return 0;
}