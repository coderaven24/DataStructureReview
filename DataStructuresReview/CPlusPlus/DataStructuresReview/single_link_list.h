#ifndef SINGLE_LINK_LIST_H
#define SINGLE_LINK_LIST_H

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
		Node* m_ptrRoot;

	private:
		class Node
		{
			friend class SingleLinkList<Object>;
			friend void TestOutputContents(SingleLinkList<char> list);

		protected:
			Node* m_ptrNext;
			Object* m_ptrValue;

		public:
			Node();
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
		m_ptrNext(0), m_ptrValue(0)
	{
	}

	template<typename Object>
	inline SingleLinkList<Object>::Node::Node(const Object& obj, Node* ptrRight)
	{
		m_ptrValue = new Object(obj);
		m_ptrNext = ptrRight;
	}

	template<typename Object>
	inline SingleLinkList<Object>::Node::Node(const Node& passByValueNode)
	{
		m_ptrValue = new Object(passByValueNode.getValue());
		m_ptrNext = passByValueNode.m_ptrNext;
	}

	template<typename Object>
	inline SingleLinkList<Object>::Node::~Node(void)
	{
		if (m_ptrValue != 0)
		{
			delete[] m_ptrValue;
			m_ptrValue = 0;
		}
	}

	template<typename Object>
	inline const Object& SingleLinkList<Object>::Node::getValue(void) const
	{
		return *this->m_ptrValue;
	}

	template<typename Object>
	inline SingleLinkList<Object>::SingleLinkList(void) :
		m_ptrRoot(0), m_size(0)
	{
	}

	template<typename Object>
	inline SingleLinkList<Object>::SingleLinkList(const SingleLinkList& passByValueList)
	{
		m_size = 0;
		m_ptrRoot = 0;

		Node* ptrRunner = passByValueList.m_ptrRoot;

		while (ptrRunner != 0)
		{
			add(*ptrRunner->m_ptrValue);
			ptrRunner = ptrRunner->m_ptrNext;
		}
	}

	template<typename Object>
	inline SingleLinkList<Object>::~SingleLinkList(void)
	{
		Node* ptrRunner = m_ptrRoot;

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
		m_ptrRoot = new Node(obj, m_ptrRoot);
		++m_size;
	}

	template<typename Object>
	inline void SingleLinkList<Object>::addLast(const Object& obj)
	{
		if (m_ptrRoot != 0)
		{
			Node* ptrRunner = m_ptrRoot;

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
		Node* ptrRunner = m_ptrRoot;

		while (ptrRunner != 0)
		{
			Node* ptrCurrent = ptrRunner;
			ptrRunner = ptrRunner->m_ptrNext;
			delete[] ptrCurrent;
		}

		m_ptrRoot = 0;
		m_size = 0;
	}

	template<typename Object>
	inline void SingleLinkList<Object>::insertAfter(const Object& obj, const Object& after)
	{
		Node* ptrRunner = m_ptrRoot;

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
		Node* ptrRunner = m_ptrRoot, *ptrPrevious = m_ptrRoot;

		while (ptrRunner != 0)
		{
			if (ptrRunner->getValue() == before)
			{
				ptrPrevious->m_ptrNext = new Node(obj, ptrRunner);
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
		Node* ptrRunner = m_ptrRoot, *ptrPrevious = m_ptrRoot;

		while (ptrRunner != 0)
		{
			if (ptrRunner->getValue() == obj)
			{
				ptrPrevious->m_ptrNext = ptrRunner->m_ptrNext;
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
		cout << "adding letters a thru m to the list" << endl;

		for (char k = 'a'; k <= 'm'; k++)
			tmp.add(k);

		TestOutputContents(tmp);

		cout << "is empty : " << tmp.isEmpty() << endl;

		cout << "adding a 'y' to the end | ";

		tmp.addLast('y');

		TestOutputContents(tmp);

		//System.out.print("removing e | ");

		//remove('e');

		//testOutputContents();

		//System.out.print("removing m | ");

		//remove('m');

		//testOutputContents();

		//System.out.print("adding z before f | ");

		//insertBefore('z', 'f');

		//testOutputContents();

		//System.out.print("adding q after z | ");

		//insertAfter('q', 'z');

		//testOutputContents();

		//System.out.println("SingleLinkList______________________");
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
		return m_ptrRoot->getValue();
	}

	void TestOutputContents(SingleLinkList<char> list)
	{
		cout << "count:" << list.size();
		SingleLinkList<char>::Node * ptrRunner = list.m_ptrRoot;

		cout << " contents:";

		while (ptrRunner != 0) {
			cout << ptrRunner->getValue() << " ";

			ptrRunner = ptrRunner->m_ptrNext;
		}

		cout << endl;
	}
}

#endif