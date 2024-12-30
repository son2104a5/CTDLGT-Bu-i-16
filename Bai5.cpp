#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}

int findMax(Node* node) {
    if (node == NULL) {
        return -1; 
    }
    int max = node->data;
    int leftMax = findMax(node->left);
    int rightMax = findMax(node->right);
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }
    return max;
}

int main() {
    Node* tree = NULL;
    tree = insertNode(tree, 4);
    tree = insertNode(tree, 3);
    tree = insertNode(tree, 6);
    tree = insertNode(tree, 2);
    tree = insertNode(tree, 5);

    int maxValue = findMax(tree);
    printf("Gia tri lon nhat trong cay: %d\n", maxValue);

    return 0;
}

