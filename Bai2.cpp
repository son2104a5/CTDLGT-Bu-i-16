#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insertNode(Node *node, int data){
	if(node == NULL){
		node = createNode(data);
	}
	if(data < node->data){
		node->left = insertNode(node->left, data);
	} else if(data > node->data) {
		node->right = insertNode(node->right, data);
	}
	return node;
}

void preOrdered(Node* node){
	if(node != NULL){
		printf("%d \t", node->data);
		preOrdered(node->left);
		preOrdered(node->right);
	}
}

void inOrdered(Node* node){
	if(node != NULL){
		inOrdered(node->left);
		printf("%d \t", node->data);
		inOrdered(node->right);
	}
}

void postOrdered(Node* node){
	if(node != NULL){
		postOrdered(node->left);
		postOrdered(node->right);
		printf("%d \t", node->data);
	}
}

int main(){
	Node* tree = NULL;
	
	tree = insertNode(tree, 4);
	tree = insertNode(tree, 3);
	tree = insertNode(tree, 6);
	tree = insertNode(tree, 2);
	tree = insertNode(tree, 5);
	
	printf("PreOrder:\t");
	preOrdered(tree);
	printf("\n");
	printf("InOrder:\t");
	inOrdered(tree);
	printf("\n");
	printf("PostOrder:\t");
	postOrdered(tree);
	return 0;
}

