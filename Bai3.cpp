#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
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

void preOrdered(Node* node) {
    if (node != NULL) {
        printf("%d\t", node->data);
        preOrdered(node->left);
        preOrdered(node->right);
    }
}

int calculateLeaf(Node* node) {
    if (node == NULL) {
        return 0;
    }
    if(node->left == NULL && node->right == NULL){
    	return 1;
	}
	return calculateLeaf(node->left) + calculateLeaf(node->right);
}

int main() {
    Node* tree = NULL;
    tree = insertNode(tree, 4);
    tree = insertNode(tree, 3);
    tree = insertNode(tree, 6);
    tree = insertNode(tree, 2);
    tree = insertNode(tree, 5);
    preOrdered(tree);
    printf("\n");

    int leaf = calculateLeaf(tree);
    printf("So la cua cay la: %d\n", leaf);

    return 0;
}

