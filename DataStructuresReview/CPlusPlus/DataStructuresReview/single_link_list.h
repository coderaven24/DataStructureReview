#ifndef SINGLE_LINK_LIST_H
#define SINGLE_LINK_LIST_H

#include "interfaces.h"

namespace datastructures
{
	template <typename Object>
	class SingleLinkList :
		public ISingleLinkList<Object>, public IDataStructureTest
	{
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
		void testOutputContents(void);

	private:
		int m_size;
		Node* m_ptrRoot;

	private:
		class Node
		{
			friend class SingleLinkList<Object>;

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
			add(ptrRunner->ptrValue);
			ptrRunner = ptrRunner->ptrNext;
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
		//System.out.println("SingleLinkList______________________");

		//System.out.println("is empty : " + isEmpty());
		//System.out.println("adding letters a thru m to the list");

		//add('a');
		//add('b');
		//add('c');
		//add('d');
		//add('e');
		//add('f');
		//add('g');
		//add('h');
		//add('i');
		//add('j');
		//add('k');
		//add('n');
		//add('m');

		//testOutputContents();

		//System.out.println("is empty : " + isEmpty());

		//System.out.print("adding a 'y' to the end | ");

		//addLast('y');

		//testOutputContents();

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
	void SingleLinkList<Object>::testOutputContents(void) {
		//System.out.print("count:" + size());

		//Node runner = root;

		//System.out.print(" contents:");

		//while (runner != null) {
		//	System.out.print(runner.getValue() + " ");

		//	runner = runner.next;
		//}

		//System.out.println(" ");
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
}

#endif