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
		friend void TestOutputContents(DoubleLinkList<char> list);

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
		void test(void);

	public:
		bool isEmpty(void) const;

	public:
		int size(void) const;

	public:
		const Object& first(void) const;
		const Object& last(void) const;

	private:
		int m_size;
		Node* m_ptrHead;
		Node* m_ptrTail;


	private:
		void passByValueHelper(DoubleLinkList<Object>* ptrList, const Node* ptrNode);

	private:
		class Node
		{
			friend class DoubleLinkList <Object>;
			friend void TestOutputContents(DoubleLinkList<char> list);

		protected:
			Node* m_ptrNext;
			Node* m_ptrPrev;
			Object  m_value;

		public:
			Node(void);
			Node(const Object& obj, Node* ptrPrev, Node* ptrRight);
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
	inline datastructures::DoubleLinkList<Object>::Node::Node(const Object& obj, Node* ptrPrev, Node* ptrRight) :
		m_value(obj), m_ptrNext(ptrRight), m_ptrPrev(ptrPrev)
	{

	}

	template<typename Object>
	inline DoubleLinkList<Object>::Node::Node(const Node& passByValueNode) : 
		m_value(passByValueNode.m_value), m_ptrNext(passByValueNode.m_ptrNext), m_ptrPrev(passByValueNode.m_ptrPrev)
	{

	}

	template<typename Object>
	inline DoubleLinkList<Object>::Node::~Node(void)
	{

	}

	template<typename Object>
	inline const Object& DoubleLinkList<Object>::Node::getValue(void) const
	{
		return this->m_value;
	}


	template<typename Object>
	inline datastructures::DoubleLinkList<Object>::DoubleLinkList(void) : 
		m_ptrHead(0), m_ptrTail(0), m_size(0)
	{
	}

	template<typename Object>
	inline datastructures::DoubleLinkList<Object>::DoubleLinkList(const DoubleLinkList& passByValueList) :
		m_ptrHead(0), m_ptrTail(0), m_size(0)
	{
		if (passByValueList.m_ptrHead != 0)
			passByValueHelper(this, passByValueList.m_ptrHead);
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::passByValueHelper(DoubleLinkList<Object>* ptrList, const Node* ptrNode)
	{
		if (ptrNode->m_ptrNext != 0)
			passByValueHelper(ptrList, ptrNode->m_ptrNext);

		ptrList->add(ptrNode->getValue());
	}


	template<typename Object>
	inline datastructures::DoubleLinkList<Object>::~DoubleLinkList(void)
	{
		Node* ptrRunner = m_ptrHead;

		while (ptrRunner != 0)
		{
			Node* ptrCurrent = ptrRunner;
			ptrRunner = ptrRunner->m_ptrNext;
			delete[] ptrCurrent;
		}
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::add(const Object& obj)
	{
		if (this->m_ptrHead != 0)
		{
			m_ptrHead = new Node(obj, 0, m_ptrHead);
			m_ptrHead->m_ptrNext->m_ptrPrev = m_ptrHead;
		}
		else
			m_ptrHead = m_ptrTail = new Node(obj, 0, 0);

		++m_size;
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::addLast(const Object& obj)
	{
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::clear(void)
	{
		Node* ptrRunner = m_ptrHead;

		while (ptrRunner != 0)
		{
			Node* ptrCurrent = ptrRunner;
			ptrRunner = ptrRunner->m_ptrNext;
			delete[] ptrCurrent;
		}

		m_ptrTail = 0;
		m_ptrHead = 0;
		m_size = 0;
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::insertAfter(const Object& obj, const Object& after)
	{
		if (this->m_ptrTail != 0)
		{

		}
		else
			m_ptrHead = m_ptrTail = new Node(obj, 0, 0);

		++m_size;
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::insertBefore(const Object& obj, const Object& before)
	{

	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::remove(const Object& obj)
	{

	}

	template<typename Object>
	inline void DoubleLinkList<Object>::test(void)
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

	template<typename Object>
	inline bool datastructures::DoubleLinkList<Object>::isEmpty(void) const
	{
		return m_size == 0;
	}

	template<typename Object>
	inline int datastructures::DoubleLinkList<Object>::size(void) const
	{
		return m_size;
	}

	template<typename Object>
	inline const Object& datastructures::DoubleLinkList<Object>::first(void) const
	{
		return m_ptrHead->getValue();
	}

	template<typename Object>
	inline const Object& datastructures::DoubleLinkList<Object>::last(void) const
	{
		return m_ptrTail->getValue();
	}

	inline void TestOutputContents(DoubleLinkList<char> list)
	{
		cout << "count:" << list.size();
		DoubleLinkList<char>::Node* ptrRunner = list.m_ptrHead;

		cout << " contents:";

		while (ptrRunner != 0) {
			cout << ptrRunner->getValue() << " ";

			ptrRunner = ptrRunner->m_ptrNext;
		}

		cout << endl;
	}
}


#endif