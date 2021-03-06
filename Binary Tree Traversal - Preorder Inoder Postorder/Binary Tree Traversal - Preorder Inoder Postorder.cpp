// Binary Tree Traversal - Preorder Inoder Postorder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

void PreOrder(struct Node *root) {
	if (root == NULL) return;

	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(Node *root) {
	if (root == NULL) return;

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

void PostOrder(Node *root) {
	if (root == NULL) return;

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

Node* Insert(Node *root, char data)
{
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

int main()
{
	Node* root = NULL;

	root = Insert(root, 'M');
	root = Insert(root, 'B');
	root = Insert(root, 'Q');
	root = Insert(root, 'Z');
	root = Insert(root, 'A');
	root = Insert(root, 'C');

	cout << "PreOrder: ";
	PreOrder(root);
	cout << "\n";

	cout << "InOrder: ";
	InOrder(root);
	cout << "\n";

	cout << "PostOrder: ";
	PostOrder(root);
	cout << "\n";

    return 0;
}

