#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
struct Node* find_min(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int count_nodes(struct Node* node) {
    if (node == NULL) return 0;
    return 1 + count_nodes(node->left) + count_nodes(node->right);
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert nodes
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 11);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    
    struct Node* minNode = find_min(root);
    printf("Deleting the smallest element: %d\n", minNode->data);
    root = deleteNode(root, minNode->data);

    printf("Inorder Traversal after deletion: ");
    inorder(root);
    printf("\n");

    
    printf("Number of nodes: %d\n", count_nodes(root));

    return 0;
}