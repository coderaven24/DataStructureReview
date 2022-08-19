#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H

#include <iostream>
using namespace std;

#include "interfaces.h"

namespace datastructures
{
	template <typename Object>
	class DoubleLinkList :
		public IDoubleLinkList<Object>, public IDataStructureTest
	{
		friend void TestOutputContents(const DoubleLinkList<char>& list);

	private:
		class Node;

	public:
		DoubleLinkList(void);
		DoubleLinkList(const DoubleLinkList& passByValueList);

	public:
		virtual ~DoubleLinkList(void);

	public:
		void add(const Object& obj);
		void addLast(const Object& obj);
		void clear(void);
		void insertAfter(const Object& obj, const Object& after);
		void insertBefore(const Object& obj, const Object& before);
		void remove(const Object& obj);
		void test(void) const;

	public:
		bool isEmpty(void) const;

	public:
		int size(void) const;

	public:
		const Object& first(void) const;
		const Object& last(void) const;

	private:
		int m_size;
		Node* m_ptrRoot;

	private:
		class Node
		{
			friend class DoubleLinkList <Object>;
			friend void TestOutputContents(const DoubleLinkList<char>& list);

		protected:
			Node* m_ptrNext;
			Node* m_ptrPrev;
			Object* m_ptrValue;

		public:
			Node(void);
			Node(const Object& obj, Node* ptrLast, Node* ptrRight);
			Node(const Node& passByValueNode);

		public:
			virtual ~Node(void);

		public:
			const Object& getValue(void) const;
		};
	};

	template<typename Object>
	inline DoubleLinkList<Object>::Node::Node(void) :
		m_ptrNext(0), m_ptrPrev(0)
	{

	}


	template<typename Object>
	inline void DoubleLinkList<Object>::test(void) const
	{
		DoubleLinkList<char> tmp;
		cout << "DoubleLinkList______________________" << endl;
		cout << "is empty : " << tmp.isEmpty() << endl;
		cout << "adding letters a thru n to the list" << endl;

		for (char k = 'a'; k <= 'n'; k++)
			tmp.add(k);

		TestOutputContents(tmp);

		cout << "is empty : " << tmp.isEmpty() << endl;

		cout << "adding a 'y' to the end | ";

		tmp.addLast('y');

		TestOutputContents(tmp);

		cout << "removing e | ";

		tmp.remove('e');

		TestOutputContents(tmp);

		cout << "removing m | ";

		tmp.remove('m');

		TestOutputContents(tmp);

		cout << "adding z before f | ";

		tmp.insertBefore('z', 'f');

		TestOutputContents(tmp);

		cout << "adding r before l | ";

		tmp.insertBefore('r', 'l');

		TestOutputContents(tmp);

		cout << "adding q after z | ";

		tmp.insertAfter('q', 'z');

		TestOutputContents(tmp);

		cout << "DoubleLinkList______________________" << endl;
	}


	inline void TestOutputContents(const DoubleLinkList<char> & list)
	{
		cout << "count:" << list.size();
		DoubleLinkList<char>::Node* ptrRunner = list.m_ptrRoot;

		cout << " contents:";

		while (ptrRunner != 0) {
			cout << ptrRunner->getValue() << " ";

			ptrRunner = ptrRunner->m_ptrNext;
		}

		cout << endl;
	}
}


#endif