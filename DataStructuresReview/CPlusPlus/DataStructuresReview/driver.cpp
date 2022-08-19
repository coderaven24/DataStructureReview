
#include <iostream>
using namespace std;

#include "single_link_list.h"
#include "double_link_list.h"
using namespace datastructures;

int main()
{
	SingleLinkList<char> * pList = new SingleLinkList<char>();
	DoubleLinkList<char>* pDList = new DoubleLinkList<char>();

	pList->test();
	pDList->test();

}
