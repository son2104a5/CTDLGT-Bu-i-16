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

int preOrdered(Node* node, int searchValue) {
    if (node == NULL) {
        return 0;
    }
    if (node->data == searchValue) {
        return 1;
    }
    printf("%d\t", node->data);
    if (preOrdered(node->left, searchValue)) {
        return 1;
    }
    if (preOrdered(node->right, searchValue)) {
        return 1;
    }
    return 0;
}

int main() {
    Node* tree = NULL;
    tree = insertNode(tree, 4);
    tree = insertNode(tree, 3);
    tree = insertNode(tree, 6);
    tree = insertNode(tree, 2);
    tree = insertNode(tree, 5);

    int searchValue;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);
    int result = preOrdered(tree, searchValue);

    printf("\n");
    if (result) {
        printf("Trong cay co phan tu ban dang tim\n");
    } else {
        printf("Trong cay khong co phan tu ban dang tim\n");
    }

    return 0;
}

