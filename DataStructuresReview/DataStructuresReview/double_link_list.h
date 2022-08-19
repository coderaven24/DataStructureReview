#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H

#include "interfaces.h"

namespace datastructures
{
	template <typename Object>
	class DoubleLinkList :
		public IDoubleLinkList<Object>, public IDataStructureTest
	{
	private:
		class Node;

	public:
		DoubleLinkList (void);
		DoubleLinkList (const DoubleLinkList & passByValueList);

	public:
		virtual ~DoubleLinkList (void);

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

		protected:
			Node* m_ptrNext;
			Node* m_ptrPrev;
			Object* m_ptrValue;

		public:
			Node();
			Node(const Object& obj, Node* ptrLast, Node* ptrRight);
			Node(const Node& passByValueNode);

		public:
			virtual ~Node(void);

		public:
			const Object& getValue(void) const;
		};
	};



#endif