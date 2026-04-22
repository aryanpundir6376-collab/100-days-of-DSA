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

// Search value in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Pick root from postorder
    int curr = postorder[*postIndex];
    (*postIndex)--;

    Node* root = newNode(curr);

    // If leaf node
    if (start == end)
        return root;

    // Find index in inorder
    int inIndex = search(inorder, start, end, curr);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Inorder element %d: ", i + 1);
        scanf("%d", &inorder[i]);
    }

    printf("Enter postorder traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("Postorder element %d: ", i + 1);
        scanf("%d", &postorder[i]);
    }

    int postIndex = n - 1;

    Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder traversal of constructed tree:\n");
    preorder(root);
    printf("\n");

    return 0;
}