#ifndef SINGLE_LINK_LIST_H
#define SINGLE_LINK_LIST_H

#include <iostream>
using namespace std;

#include "interfaces.h"

namespace datastructures
{
	template <typename Object>
	class SingleLinkList :
		public ISingleLinkList<Object>, public IDataStructureTest
	{
		friend void TestOutputContents(SingleLinkList<char> list);

	private:
		class Node;

	public:
		SingleLinkList(void);
		SingleLinkList(const SingleLinkList& passByValueList);

	public:
		virtual ~SingleLinkList(void);

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

	private:
		int m_size;
		Node* m_ptrHead;

	private:
		void passByValueHelper(SingleLinkList<Object>* ptrList, const Node* ptrNode);

	private:
		class Node
		{
			friend class SingleLinkList<Object>;
			friend void TestOutputContents(SingleLinkList<char> list);

		protected:
			Node* m_ptrNext;
			Object m_value;

		public:
			Node(void);
			Node(const Object& obj, Node* ptrRight);
			Node(const Node& passByValueNode);

		public:
			virtual ~Node(void);

		public:
			const Object& getValue(void) const;
		};
	};

	template<typename Object>
	inline SingleLinkList<Object>::Node::Node(void) :
		m_ptrNext(0)
	{
	}

	template<typename Object>
	inline SingleLinkList<Object>::Node::Node(const Object& obj, Node* ptrRight) :
		m_value(obj), m_ptrNext(ptrRight)
	{

	}

	template<typename Object>
	inline SingleLinkList<Object>::Node::Node(const Node& passByValueNode) :
		m_value(passByValueNode.m_value), m_ptrNext(passByValueNode.m_ptrNext)
	{

	}

	template<typename Object>
	inline SingleLinkList<Object>::Node::~Node(void)
	{

	}

	template<typename Object>
	inline const Object& SingleLinkList<Object>::Node::getValue(void) const
	{
		return this->m_value;
	}

	template<typename Object>
	inline SingleLinkList<Object>::SingleLinkList(void) :
		m_ptrHead(0), m_size(0)
	{
	}

	template<typename Object>
	inline SingleLinkList<Object>::SingleLinkList(const SingleLinkList& passByValueList)
	{
		m_size = 0;
		m_ptrHead = 0;

		if (passByValueList.m_ptrHead != 0)
			passByValueHelper(this, passByValueList.m_ptrHead);
	}

	template<typename Object>
	inline void datastructures::SingleLinkList<Object>::passByValueHelper(SingleLinkList<Object> * ptrList, const Node * ptrNode)
	{
		if (ptrNode->m_ptrNext != 0)
			passByValueHelper(ptrList, ptrNode->m_ptrNext);

		ptrList->add(ptrNode->getValue());
	}

	template<typename Object>
	inline SingleLinkList<Object>::~SingleLinkList(void)
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
	inline void SingleLinkList<Object>::add(const Object& obj)
	{
		m_ptrHead = new Node(obj, m_ptrHead);
		++m_size;
	}

	template<typename Object>
	inline void SingleLinkList<Object>::addLast(const Object& obj)
	{
		if (m_ptrHead != 0)
		{
			Node* ptrRunner = m_ptrHead;

			while (ptrRunner->m_ptrNext != 0)
				ptrRunner = ptrRunner->m_ptrNext;

			ptrRunner->m_ptrNext = new Node(obj, 0);
			++m_size;
		}
		else
			add(obj);
	}

	template<typename Object>
	inline void SingleLinkList<Object>::clear(void)
	{
		Node* ptrRunner = m_ptrHead;

		while (ptrRunner != 0)
		{
			Node* ptrCurrent = ptrRunner;
			ptrRunner = ptrRunner->m_ptrNext;
			delete[] ptrCurrent;
		}

		m_ptrHead = 0;
		m_size = 0;
	}

	template<typename Object>
	inline void SingleLinkList<Object>::insertAfter(const Object& obj, const Object& after)
	{
		Node* ptrRunner = m_ptrHead;

		while (ptrRunner != 0)
		{
			if (ptrRunner->getValue() == after)
			{
				ptrRunner->m_ptrNext = new Node(obj, ptrRunner->m_ptrNext);
				++m_size;
				return;
			}
			else
				ptrRunner = ptrRunner->m_ptrNext;
		}
	}

	template<typename Object>
	inline void SingleLinkList<Object>::insertBefore(const Object& obj, const Object& before)
	{
		Node* ptrRunner = m_ptrHead, *ptrPrevious = 0;

		while (ptrRunner != 0)
		{
			if (ptrRunner->getValue() == before)
			{
				if(ptrPrevious != 0)
					ptrPrevious->m_ptrNext = new Node(obj, ptrRunner);

				else
					m_ptrHead = new Node(obj, m_ptrHead);

				++m_size;
				return;
			}
			else
			{
				ptrPrevious = ptrRunner;
				ptrRunner = ptrRunner->m_ptrNext;
			}
		}
	}

	template<typename Object>
	inline void SingleLinkList<Object>::remove(const Object& obj)
	{
		Node* ptrRunner = m_ptrHead, *ptrPrevious = 0;

		while (ptrRunner != 0)
		{
			if (ptrRunner->getValue() == obj)
			{
				if (ptrPrevious != 0)
					ptrPrevious->m_ptrNext = ptrRunner->m_ptrNext;

				else
					m_ptrHead = m_ptrHead->m_ptrNext;

				delete[] ptrRunner;
				--m_size;
				return;
			}
			else
			{
				ptrPrevious = ptrRunner;
				ptrRunner = ptrRunner->m_ptrNext;
			}
		}
	}

	template<typename Object>
	inline void SingleLinkList<Object>::test(void)
	{
		SingleLinkList<char> tmp;
		cout << "SingleLinkList______________________" << endl;
		cout << "is empty : " << tmp.isEmpty()<< endl;
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

		cout << "SingleLinkList______________________"<<endl;
	}

	template<typename Object>
	inline bool SingleLinkList<Object>::isEmpty(void) const
	{
		return m_size == 0;
	}

	template<typename Object>
	inline int SingleLinkList<Object>::size(void) const
	{
		return m_size;
	}

	template<typename Object>
	inline const Object& SingleLinkList<Object>::first(void) const
	{
		return m_ptrHead->getValue();
	}

	inline void TestOutputContents(SingleLinkList<char> list)
	{
		cout << "count:" << list.size();
		SingleLinkList<char>::Node * ptrRunner = list.m_ptrHead;

		cout << " contents:";

		while (ptrRunner != 0) {
			cout << ptrRunner->getValue() << " ";

			ptrRunner = ptrRunner->m_ptrNext;
		}

		cout << endl;
	}
}

#endif