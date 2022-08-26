#include <iostream>
using namespace std;

#include "single_link_list.h"
#include "double_link_list.h"
#include "binary_tree.h"
using namespace datastructures;

void outputInt(const int& i)
{
	cout << i << endl;
}

int main()
{
	SingleLinkList<char>* pList = new SingleLinkList<char>();
	DoubleLinkList<char>* pDList = new DoubleLinkList<char>();

	pList->test();
	pDList->test();

	cout << "Hello world" << endl;
	int a = 0;
	void (*foo)(const int&);
	foo = &outputInt;
	datastructures::BinaryTree<int> bt;

	for (int i = 0; i < 1000; i++)
		bt.insert(i);

	bt.visitNodes(foo);
}