#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cassert>
#include <fstream>
#include <vector>
using namespace std;

namespace datastructures
{
	template <typename Object>
	class BinaryTree
	{
	public:
		class Node
		{
		public:
			Node(void);
			Node(const Object& datum);

		public:
			Node* mPtrLeft;
			Node* mPtrRight;
			Object mDatum;
		};

	public:
		BinaryTree(void);
		BinaryTree(const BinaryTree& btPassed);
		~BinaryTree(void);

	public:
		void insert(const Object& datum);
		void clear(void);

	public:
		const bool getMinDatum(Object& datum) const;
		const bool getMaxDatum(Object& datum) const;
		const bool getDatum(Object& datum) const;

	public:
		void collectNodes(vector<Object>& vec) const;
		void visitNodes(void (*ptrFun)(Object&));
		void visitNodes(void (*ptrFun)(const Object&));

	private:
		void visitHelper(Node*, void (*ptrFun)(Object&));
		void visitHelper(Node*, void (*ptrFun)(const Object&));

	public:
		const BinaryTree<Object>& operator = (const BinaryTree<Object>& btRight);

	public:
		inline const unsigned int getSize(void) const {
			return mSize;
		}

		inline const bool extract(const Object& datum) {
			return extractHelper(datum, mPtrRoot);
		}

	protected:
		inline Node* getRoot(void) const {
			return mPtrRoot;
		}

	protected:
		void ostreamHelper(const Node* pVisit, ostream& oOutput) const;

	private:
		const bool extractHelper(const Object& datum, Node*& pUnwantedNode);

	private:
		void copyVisitor(const Node* pVisit, BinaryTree<Object>& btToBeInserted) const;
		void collectHelper(Node*, vector<Object>& vec) const;

	private:
		inline Node* getMinPointer(Node* ptrWantedNode) const {
			if (ptrWantedNode)
			{
				while (ptrWantedNode->mPtrLeft)
					ptrWantedNode = ptrWantedNode->mPtrLeft;
			}

			return ptrWantedNode;
		}

		inline Node* getMaxPointer(Node* ptrWantedNode) const {
			if (ptrWantedNode)
			{
				while (ptrWantedNode->mPtrRight)
					ptrWantedNode = ptrWantedNode->mPtrRight;
			}

			return ptrWantedNode;
		}

	private:
		Node* mPtrRoot;
		unsigned int mSize;

	public:
		friend ostream& operator<<(ostream& oOutput, const BinaryTree<Object>& btToBeOutputted)
		{
			btToBeOutputted.ostreamHelper(btToBeOutputted.getRoot(), oOutput);
			return oOutput;
		}
	};

	template <typename Object>
	inline BinaryTree<Object>::Node::Node(const Object& datum) :
		mPtrLeft(0), mPtrRight(0)
	{
		mDatum = datum;
	}

	template <typename Object>
	inline BinaryTree<Object>::Node::Node(void) :
		mPtrLeft(0), mPtrRight(0)
	{
	}

	template <typename Object>
	BinaryTree<Object>::BinaryTree(void) :
		mPtrRoot(0), mSize(0)
	{
	}

	template <typename Object>
	BinaryTree<Object>::BinaryTree(const BinaryTree<Object>& btPassed) :
		mPtrRoot(0)
	{
		copyVisitor(btPassed.mPtrRoot, this);
	}

	template <typename Object>
	BinaryTree<Object>::~BinaryTree(void)
	{
		clear();
	}

	template <typename Object>
	void BinaryTree<Object>::insert(const Object& datum)
	{
		Node** ppRunner = &mPtrRoot;

		while (*ppRunner)
		{
			if (datum < (*ppRunner)->mDatum)
				ppRunner = &((*ppRunner)->mPtrLeft);

			else
				ppRunner = &((*ppRunner)->mPtrRight);
		}

		++mSize;
		*ppRunner = new Node(datum);
	}

	template <typename Object>
	const bool BinaryTree<Object>::extractHelper(const Object& datum, Node*& pUnwantedNode)
	{
		if (!pUnwantedNode)
			return false;

		else if (datum < pUnwantedNode->mDatum)
			return extractHelper(datum, pUnwantedNode->mPtrLeft);

		else if (pUnwantedNode->mDatum < datum)
			return extractHelper(datum, pUnwantedNode->mPtrRight);

		else if (pUnwantedNode->mPtrLeft && pUnwantedNode->mPtrRight)
		{
			pUnwantedNode->mDatum = getMinPointer(pUnwantedNode->mPtrRight)->mDatum;
			getMinPointer(pUnwantedNode->mPtrRight)->mDatum = datum;

			return extractHelper(datum, pUnwantedNode->mPtrRight);
		}
		else
		{
			Node* ptrNodeBeforeRedirection = pUnwantedNode;

			if (pUnwantedNode->mPtrLeft)
				pUnwantedNode = pUnwantedNode->mPtrLeft;

			else
				pUnwantedNode = pUnwantedNode->mPtrRight;

			--mSize;
			delete ptrNodeBeforeRedirection;

			return true;
		}
	}

	template <typename Object>
	const bool BinaryTree<Object>::getMinDatum(Object& datum) const
	{
		Node* pMin = getMinPointer(mPtrRoot);

		if (pMin)
		{
			datum = pMin->mDatum;
			return true;
		}

		return false;
	}

	template <typename Object>
	const bool BinaryTree<Object>::getMaxDatum(Object& datum) const
	{
		Node* pMax = getMaxPointer(mPtrRoot);

		if (pMax)
		{
			datum = pMax->mDatum;
			return true;
		}

		return false;
	}

	template <typename Object>
	void BinaryTree<Object>::ostreamHelper(const BinaryTree<Object>::Node* pVisit, ostream& oOutput) const
	{
		if (pVisit)
		{
			ostreamHelper(pVisit->mPtrLeft, oOutput);
			oOutput << pVisit->mDatum << ' ';
			ostreamHelper(pVisit->mPtrRight, oOutput);
		}
	}

	template <typename Object>
	void BinaryTree<Object>::clear(void)
	{
		while (mPtrRoot)
			extract(mPtrRoot->mDatum);
	}

	template <typename Object>
	void BinaryTree<Object>::copyVisitor(const Node* pVisit, BinaryTree<Object>& btToBeInserted) const
	{
		if (pVisit)
		{
			btToBeInserted.insert(pVisit->mDatum);
			copyVisitor(pVisit->mPtrLeft, btToBeInserted);
			copyVisitor(pVisit->mPtrRight, btToBeInserted);
		}
	}

	template <typename Object>
	const BinaryTree<Object>& BinaryTree<Object>::operator = (const BinaryTree<Object>& btRight)
	{
		if (this != &btRight)
		{
			clear();
			btRight.copyVisitor(btRight.mPtrRoot, *this);
		}

		return *this;
	}

	template <typename Object>
	const bool BinaryTree<Object>::getDatum(Object& datum) const
	{
		Node* pTemp = mPtrRoot;

		while (pTemp)
		{
			if (pTemp->mDatum < datum)
				pTemp = pTemp->mPtrRight;

			else if (pTemp->mDatum > datum)
				pTemp = pTemp->mPtrLeft;

			else
			{
				datum = pTemp->mDatum;
				return true;
			}
		}

		return false;
	}

	template <typename Object>
	void BinaryTree<Object>::collectNodes(vector<Object>& vec) const
	{
		collectHelper(mPtrRoot, vec);
	}

	template <typename Object>
	void BinaryTree<Object>::collectHelper(BinaryTree<Object>::Node* ptrNode, vector<Object>& vec) const
	{
		if (!ptrNode)
			return;

		if (ptrNode->mPtrLeft)
			collectHelper(ptrNode->mPtrLeft, vec);

		vec.push_back(ptrNode->mDatum);

		if (ptrNode->mPtrRight)
			collectHelper(ptrNode->mPtrRight, vec);
	}

	template <typename Object>
	void BinaryTree<Object>::visitNodes(void (*ptrFun)(const Object&))
	{
		visitHelper(mPtrRoot, ptrFun);
	}

	template <typename Object>
	void BinaryTree<Object>::visitHelper(Node* ptrNode, void (*ptrFun)(const Object&))
	{
		if (!ptrNode)
			return;

		if (ptrNode->mPtrLeft)
			visitHelper(ptrNode->mPtrLeft, ptrFun);

		(*ptrFun)(ptrNode->mDatum);

		if (ptrNode->mPtrRight)
			visitHelper(ptrNode->mPtrRight, ptrFun);
	}

	template <typename Object>
	void BinaryTree<Object>::visitNodes(void (*ptrFun)(Object&))
	{
		visitHelper(mPtrRoot, ptrFun);
	}

	template <typename Object>
	void BinaryTree<Object>::visitHelper(Node* ptrNode, void (*ptrFun)(Object&))
	{
		if (!ptrNode)
			return;

		if (ptrNode->mPtrLeft)
			visitHelper(ptrNode->mPtrLeft, ptrFun);

		(*ptrFun)(ptrNode->mDatum);

		if (ptrNode->mPtrRight)
			visitHelper(ptrNode->mPtrRight, ptrFun);
	}
}
#endif
