#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int countNodesGreaterThanX(Node* node, int X) {
    if (node == NULL) {
        return 0;
    }
    int count = 0;
    if (node->data > X) {
        count++;
    }
    count += countNodesGreaterThanX(node->left, X);
    count += countNodesGreaterThanX(node->right, X);
    return count;
}

int main() {
    Node* root = NULL;
    int n, X, value;

    printf("Nhap so luong nut muon them vao cay: ");
    scanf("%d", &n);

    srand(time(NULL));
    printf("Cac gia tri duoc chen vao cay: ");
    for (int i = 0; i < n; i++) {
        value = rand() % 100;
        printf("%d ", value);
        root = insertNode(root, value);
    }
    printf("\n");

    printf("Nhap gia tri X: ");
    scanf("%d", &X);

    int result = countNodesGreaterThanX(root, X);
    printf("So nut co gia tri lon hon %d: %d\n", X, result);

    return 0;
}

