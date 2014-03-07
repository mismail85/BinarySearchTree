#pragma once

#include <string>

using namespace std;

class BinarySearchTree
{
private:
	struct Node
	{
		Node* left;
		Node* right;
		int data;
	};
	Node* root;
	
	Node * createNode(int data)const;
	void printInOrder(Node * node);
public:
	BinarySearchTree(void);
	~BinarySearchTree(void);
	void insert(int data);
	int max();
	int min();
	int size();
	void printTreeItems();
	void storeInFile(string & filePath);
	void readFromFile(string & filePath);

};

