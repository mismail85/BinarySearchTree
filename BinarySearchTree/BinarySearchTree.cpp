#include "stdafx.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <stack>

BinarySearchTree::BinarySearchTree(void)
	:root(NULL)
{
}


BinarySearchTree::~BinarySearchTree(void)
{
	//delete all items
}

void BinarySearchTree::insert(int data)
{
	Node * parent = NULL;
	Node * node = createNode(data);
	if(root == NULL){
		root = node;
	}
	else 
	{
		Node * cur = root;
		while(cur){
			parent = cur;
			if(node->data <= cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		if(node->data <= parent->data)
			parent->left = node;
		else
			parent->right = node;
	}
}

BinarySearchTree::Node * BinarySearchTree::createNode(int data)const
{
	Node *node = new Node;
	node->left = NULL;
	node->right = NULL;
	node->data = data;

	return node;
}

//print inorder
void BinarySearchTree::printTreeItems()
{
	printInOrder(root);
}

void BinarySearchTree::printInOrder(Node * node)
{
	if(node != NULL){
		if(node->left) printInOrder(node->left);
		cout << node->data << endl;
		if(node->right) printInOrder(node->right);
	}
}
int BinarySearchTree::max()
{
	if(root != NULL){
		Node * node = root;
		while(node->right){
			node = node->right;
		}
		return node->data;
	}
}
int BinarySearchTree::min()
{
	if(root != NULL){
		Node * node = root;
		while(node->left){
			node = node->left;
		}
		return node->data;
	}
}
int BinarySearchTree::size()
{
	int size = 0;
	if(root != NULL){
	stack<Node*> parentStack;
	Node * node = root;
	while(!parentStack.empty() || node != NULL){
		if(node != NULL){
			parentStack.push(node);
			node = node->left;
		}
		else{
			node = parentStack.top();
			parentStack.pop();
			++size;
			node = node->right;
		}
	}
	}
	return size;
}

void BinarySearchTree::storeInFile(string & filePath)
{
	fstream file;
	file.open(filePath.c_str(), fstream::out);
	stack<Node*> parentStack;
	Node * node = root;
	while (!parentStack.empty() || node != NULL){
		if (node != NULL){
			parentStack.push(node);
			node = node->left;
		}
		else{
			node = parentStack.top();
			parentStack.pop();
			file << node->data <<endl;
			node = node->right;
		}
	}
	file.close();
}

void BinarySearchTree::readFromFile(string & filePath)
{
	fstream file;
	file.open(filePath.c_str(), fstream::in);

	int x;
	while(!file.eof()){

		file >> x;

		if(!file.eof())
			insert(x);
	}
	file.close();
}
