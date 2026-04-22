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

// Find index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // Pick current root from preorder
    int curr = preorder[*preIndex];
    (*preIndex)++;

    Node* root = newNode(curr);

    // If no children
    if (start == end)
        return root;

    // Find index in inorder
    int inIndex = search(inorder, start, end, curr);

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Postorder traversal
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Preorder element %d: ", i + 1);
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Inorder element %d: ", i + 1);
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Postorder traversal of constructed tree:\n");
    postorder(root);
    printf("\n");

    return 0;
}