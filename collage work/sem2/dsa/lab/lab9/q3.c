#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Structure for binary tree node
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


TreeNode* buildTreeFromPrefix(char* prefix, int* index) {
    char c = prefix[*index];
    *index = *index + 1;
    
    TreeNode* newNode = createNode(c);
    
    if (isOperator(c)) {
        newNode->left = buildTreeFromPrefix(prefix, index);
        newNode->right = buildTreeFromPrefix(prefix, index);
    }
    
    return newNode;
}


void printPostfix(TreeNode* root) {
    if (root == NULL) return;
    
    printPostfix(root->left);
    printPostfix(root->right);
    printf("%c", root->data);
}


void freeTree(TreeNode* root) {
    if (root == NULL) return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char prefix[100];
    int index = 0;
    
    printf("Enter the prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);
    prefix[strcspn(prefix, "\n")] = '\0'; 
    TreeNode* root = buildTreeFromPrefix(prefix, &index);
    
    printf("Postfix expression: ");
    printPostfix(root);
    printf("\n");
    
    freeTree(root);
    
    return 0;
}