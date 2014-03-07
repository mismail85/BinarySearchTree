// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearchTree.h"

#include <iostream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	BinarySearchTree tree;

	//tree.insert(8);
	//tree.insert(3);
	//tree.insert(10);
	//tree.insert(1);
	//tree.insert(6);
	//tree.insert(4);
	//tree.insert(7);
	//tree.insert(14);
	//tree.insert(13);

	tree.readFromFile(string("d:/tree.txt"));
	cout << tree.min();

	return 0;
}

