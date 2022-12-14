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
		friend void TestOutputContents(const SingleLinkList<char>& list);

	private:
		class Node;

	public:
		SingleLinkList(void);
		SingleLinkList(const SingleLinkList& passByValueList);

	public:
		virtual ~SingleLinkList(void);

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
		class Node
		{
			friend class SingleLinkList<Object>;
			friend void TestOutputContents(const SingleLinkList<char>& list);

		protected:
			Node* mPtrNext;
			Object mValue;

		public:
			Node(void);
			Node(const Object& obj, Node* ptrNext);
			Node(const Node& passByValueNode);

		public:
			virtual ~Node(void);

		public:
			const Object& getValue(void) const;
		};
	};

	template<typename Object>
	inline SingleLinkList<Object>::Node::Node(void) :
		mPtrNext(0)
	{
	}

	template<typename Object>
	inline SingleLinkList<Object>::Node::Node(const Object& obj, Node* ptrNext) :
		mValue(obj), mPtrNext(ptrNext)
	{

	}

	template<typename Object>
	inline SingleLinkList<Object>::Node::Node(const Node& passByValueNode) :
		mValue(passByValueNode.mValue), mPtrNext(passByValueNode.mPtrNext)
	{

	}
	
	template<typename Object>
	inline SingleLinkList<Object>::Node::~Node(void)
	{

	}

	template<typename Object>
	inline const Object& SingleLinkList<Object>::Node::getValue(void) const
	{
		return this->mValue;
	}
	
	template<typename Object>
	inline SingleLinkList<Object>::SingleLinkList(void) :
		mPtrHead(0), mPtrTail(0), mSize(0)
	{
	}
	
	template<typename Object>
	inline SingleLinkList<Object>::SingleLinkList(const SingleLinkList& passByValueList) :
		mPtrHead(0), mPtrTail(0), mSize(0)
	{
		Node * ptrRunner = passByValueList.mPtrHead;

		while (ptrRunner != 0)
		{
			append(ptrRunner->mValue);
			ptrRunner = ptrRunner->mPtrNext;
		}
	}

	template<typename Object>
	inline SingleLinkList<Object>::~SingleLinkList(void)
	{
		Node* ptrRunner = mPtrHead;

		while (ptrRunner != 0)
		{
			Node* ptrCurrent = ptrRunner;
			ptrRunner = ptrRunner->mPtrNext;
			delete[] ptrCurrent;
		}
	}

	template<typename Object>
	inline void SingleLinkList<Object>::prepend(const Object& obj)
	{
		mPtrHead  = new Node(obj,mPtrHead);

		if(mPtrTail == 0)
			mPtrTail = mPtrHead;

		mSize++;
	}
	
	template<typename Object>
	inline void SingleLinkList<Object>::append(const Object& obj)
	{
		Node * ptrTmp = new Node(obj,0);

		if (mPtrHead != 0)
			mPtrTail->mPtrNext = ptrTmp;

		else
			mPtrHead = ptrTmp;

		mPtrTail = ptrTmp;
		mSize++;
	}

	template<typename Object>
	inline void SingleLinkList<Object>::clear(void)
	{
		Node* ptrRunner = mPtrHead;

		while (ptrRunner != 0)
		{
			Node* ptrCurrent = ptrRunner;
			ptrRunner = ptrRunner->mPtrNext;
			delete[] ptrCurrent;
		}

		mPtrTail = 0;
		mPtrHead = 0;
		mSize = 0;
	}

	template<typename Object>
	inline void SingleLinkList<Object>::insertAfter(const Object& obj, const Object& after)
	{
		Node* ptrRunner = mPtrHead;

		while (ptrRunner != 0)
		{
			if (ptrRunner->mValue != after)
				ptrRunner = ptrRunner->mPtrNext;

			else
			{
				Node* ptrTemp = ptrRunner->mPtrNext;
				ptrRunner->mPtrNext = new Node(obj, ptrTemp);
				++mSize;

				if (mPtrTail == ptrRunner)
					mPtrTail = ptrRunner->mPtrNext;

				break;
			}
		}
	}

	template<typename Object>
	inline void SingleLinkList<Object>::insertBefore(const Object& obj, const Object& before)
	{
		Node* ptrRunner = mPtrHead;
		Node* ptrPrev = 0;

		while (ptrRunner != 0)
		{
			if (ptrRunner->mValue != before)
			{
				ptrPrev = ptrRunner;
				ptrRunner = ptrRunner->mPtrNext;
			}
			else
			{
				if (ptrPrev == 0)
					mPtrHead = new Node(obj, mPtrHead);

				else
					ptrPrev->mPtrNext = new Node(obj, ptrPrev->mPtrNext);

				++mSize;

				break;
			}
		}
	}

	template<typename Object>
	inline void SingleLinkList<Object>::remove(const Object& obj)
	{
		Node* ptrRunner = mPtrHead;
		Node* ptrPrev = 0;

		while (ptrRunner != 0)
		{
			if (ptrRunner->mValue == obj)
			{
				if (ptrRunner == mPtrHead)
					mPtrHead = ptrRunner->mPtrNext;

				else
					ptrPrev->mPtrNext = ptrRunner->mPtrNext;

				if (ptrRunner == mPtrTail)
					mPtrTail = ptrPrev;

				--mSize;
				delete[] ptrRunner;
				break;
			}

			ptrPrev = ptrRunner;
			ptrRunner = ptrRunner->mPtrNext;
		}
	}

	template<typename Object>
	inline bool SingleLinkList<Object>::isEmpty(void) const
	{
		return mSize == 0;
	}

	template<typename Object>
	inline int SingleLinkList<Object>::size(void) const
	{
		return mSize;
	}

	template<typename Object>
	inline const Object& SingleLinkList<Object>::first(void) const
	{
		return mPtrHead->getValue();
	}

	template<typename Object>
	inline const Object& SingleLinkList<Object>::last(void) const
	{
		return mPtrTail->getValue();
	}

	template<typename Object>
	inline void SingleLinkList<Object>::test(void)
	{
		SingleLinkList<char> tmp;
		cout << "SingleLinkList____________________________________________" << endl;
		cout << "is empty : " << tmp.isEmpty() << endl;
		cout << "adding letters a thru n to the list" << endl;

		for (char k = 'a'; k <= 'n'; k++)
			tmp.append(k);

		TestOutputContents(tmp);

		cout << "is empty : " << tmp.isEmpty() << endl;

		cout << "adding a 'y' to the front | ";

		tmp.prepend('y');

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

		cout << "adding q after n | ";

		tmp.insertAfter('q', 'n');

		TestOutputContents(tmp);

		cout << "adding 3 after n | ";

		tmp.insertAfter('3', 'n');

		TestOutputContents(tmp);

		cout << "SingleLinkList____________________________________________" << endl;
	}

	inline void TestOutputContents(const SingleLinkList<char> & list)
	{
		cout << "count:" << list.size();
		SingleLinkList<char>::Node* ptrRunner = list.mPtrHead;

		cout << " contents:";

		while (ptrRunner != 0) {
			cout << ptrRunner->getValue() << " ";

			ptrRunner = ptrRunner->mPtrNext;
		}

		cout << endl;
	}
}

#endif