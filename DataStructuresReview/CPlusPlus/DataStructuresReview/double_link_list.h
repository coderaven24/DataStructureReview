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
		friend void TestOutputContents(const DoubleLinkList<char> & list);

	private:
		class Node;

	public:
		DoubleLinkList(void);
		DoubleLinkList(const DoubleLinkList& passByValueList);

	public:
		virtual ~DoubleLinkList(void);

	public:
		void append(const Object& obj);
		void prepend(const Object& obj);
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
		int mSize;
		Node* mPtrHead;
		Node* mPtrTail;

	private:
		void passByValueHelper(DoubleLinkList<Object>* ptrList, const Node* ptrNode);

	private:
		class Node
		{
			friend class DoubleLinkList <Object>;
			friend void TestOutputContents(const DoubleLinkList<char>& list);

		protected:
			Node* m_ptrNext;
			Node* m_ptrPrev;
			Object  m_value;

		public:
			Node(void);
			Node(const Object& obj, Node* ptrPrev, Node* ptrRight);

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
		mPtrHead(0), mPtrTail(0), mSize(0)
	{
	}

	template<typename Object>
	inline datastructures::DoubleLinkList<Object>::DoubleLinkList(const DoubleLinkList& passByValueList) :
		mPtrHead(0), mPtrTail(0), mSize(0)
	{
		Node* ptrRunner = passByValueList.mPtrHead;

		while (ptrRunner != 0)
		{
			append(ptrRunner->mValue);
			ptrRunner = ptrRunner->mPtrNext;
		}
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::passByValueHelper(DoubleLinkList<Object>* ptrList, const Node* ptrNode)
	{
		if (ptrNode->m_ptrNext != 0)
			passByValueHelper(ptrList, ptrNode->m_ptrNext);

		ptrList->append(ptrNode->getValue());
	}

	template<typename Object>
	inline datastructures::DoubleLinkList<Object>::~DoubleLinkList(void)
	{
		Node* ptrRunner = mPtrHead;

		while (ptrRunner != 0)
		{
			Node* ptrCurrent = ptrRunner;
			ptrRunner = ptrRunner->m_ptrNext;
			delete[] ptrCurrent;
		}
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::prepend(const Object& obj)
	{
		if (this->mPtrHead != 0)
		{
			mPtrHead = new Node(obj, 0, mPtrHead);
			mPtrHead->m_ptrNext->m_ptrPrev = mPtrHead;
		}
		else
			mPtrHead = mPtrTail = new Node(obj, 0, 0);

		++mSize;
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::append(const Object& obj)
	{
		if (this->mPtrTail != 0)
		{
			mPtrTail = new Node(obj, mPtrTail, 0);
			mPtrTail->m_ptrPrev->m_ptrNext = mPtrTail;
		}
		else
			mPtrHead = mPtrTail = new Node(obj, 0, 0);

		++mSize;
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::clear(void)
	{
		Node* ptrRunner = mPtrHead;

		while (ptrRunner != 0)
		{
			Node* ptrCurrent = ptrRunner;
			ptrRunner = ptrRunner->m_ptrNext;
			delete[] ptrCurrent;
		}

		mPtrTail = 0;
		mPtrHead = 0;
		mSize = 0;
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::insertAfter(const Object& obj, const Object& after)
	{
		Node* ptrRunner = mPtrHead;

		while (ptrRunner != 0)
		{
			if (ptrRunner->m_value == after)
			{
				ptrRunner->m_ptrNext = new Node(obj, ptrRunner, ptrRunner->m_ptrNext);

				if (ptrRunner->m_ptrNext->m_ptrNext != 0)
					ptrRunner->m_ptrNext->m_ptrNext->m_ptrPrev = ptrRunner->m_ptrNext;

				else
					mPtrTail = ptrRunner->m_ptrNext;

				++mSize;
			}

			ptrRunner = ptrRunner->m_ptrNext;
		}
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::insertBefore(const Object& obj, const Object& before)
	{
		Node* ptrRunner = mPtrHead;

		while (ptrRunner != 0)
		{
			if (ptrRunner->m_value == before)
			{
				if (this->mPtrHead != ptrRunner)
				{
					ptrRunner->m_ptrPrev->m_ptrNext = new Node(obj, ptrRunner->m_ptrPrev, ptrRunner);
					ptrRunner->m_ptrPrev = ptrRunner->m_ptrPrev->m_ptrNext;
				}
				else
				{
					mPtrHead = new Node(obj, 0, mPtrHead);
					mPtrHead->m_ptrNext->m_ptrPrev = mPtrHead;
				}

				++mSize;
			}

			ptrRunner = ptrRunner->m_ptrNext;
		}
	}

	template<typename Object>
	inline void datastructures::DoubleLinkList<Object>::remove(const Object& obj)
	{

	}

	template<typename Object>
	inline void DoubleLinkList<Object>::test(void)
	{
		DoubleLinkList<char> tmp;
		cout << endl << "DoubleLinkList______________________" << endl;
		cout << endl << "is empty : " << tmp.isEmpty() << endl;
		cout << endl << "adding letters a thru n to the list" << endl;

		for (char k = 'a'; k <= 'n'; k++)
			tmp.append(k);

		TestOutputContents(tmp);

		cout << endl << "is empty : " << tmp.isEmpty() << endl;

		cout <<endl<< "adding a 'y' to the end";

		tmp.prepend('y');

		TestOutputContents(tmp);

		cout << endl << "removing e";

		tmp.remove('e');

		TestOutputContents(tmp);

		cout << endl << "removing m";

		tmp.remove('m');

		TestOutputContents(tmp);

		cout << endl << "adding z before f";

		tmp.insertBefore('z', 'f');

		TestOutputContents(tmp);

		cout << endl << "adding r before l";

		tmp.insertBefore('r', 'l');

		TestOutputContents(tmp);

		cout << endl << "adding q after z";

		tmp.insertAfter('q', 'z');

		TestOutputContents(tmp);

		cout << endl << "adding 3 after a";

		tmp.insertAfter('3', 'a');

		TestOutputContents(tmp);



		cout << endl << "DoubleLinkList______________________" << endl;
	}

	template<typename Object>
	inline bool datastructures::DoubleLinkList<Object>::isEmpty(void) const
	{
		return mSize == 0;
	}

	template<typename Object>
	inline int datastructures::DoubleLinkList<Object>::size(void) const
	{
		return mSize;
	}

	template<typename Object>
	inline const Object& datastructures::DoubleLinkList<Object>::first(void) const
	{
		return mPtrHead->getValue();
	}

	template<typename Object>
	inline const Object& datastructures::DoubleLinkList<Object>::last(void) const
	{
		return mPtrTail->getValue();
	}

	inline void TestOutputContents(const DoubleLinkList<char>& list)
	{
		cout <<endl<< "count:" << list.size() << endl;
		DoubleLinkList<char>::Node* ptrRunner = list.mPtrHead;

		cout<<"(head to Tail):";

		while (ptrRunner != 0) {
			cout << ptrRunner->getValue() << " ";

			ptrRunner = ptrRunner->m_ptrNext;
		}

		cout << endl<<"(Tail to Head):";

		ptrRunner = list.mPtrTail;

		while (ptrRunner != 0) {
			cout << ptrRunner->getValue() << " ";
			ptrRunner = ptrRunner->m_ptrPrev;
		}


		cout << endl;
	}
}


#endif