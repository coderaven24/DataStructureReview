#ifndef INTERFACES_H
#define INTERFACES_H


namespace datastructures
{
	// C++ can only do interfaces through abstract base classes
	// there is no keyword interface
	class IDataStructureTest
	{
	public:
		virtual void test(void) = 0;
	};


	// c++ also uses templates as it has no base class object to work with
	template <typename Object>
	class ISingleLinkList
	{
	public:
		virtual void append(const Object& obj) = 0;
		virtual void prepend(const Object& obj) = 0;
		virtual void clear(void) = 0;
		virtual void insertAfter(const Object& obj, const Object& after) = 0;
		virtual void insertBefore(const Object& obj, const Object& before) = 0;
		virtual void remove(const Object& obj) = 0;

	public:
		virtual bool isEmpty(void) const = 0;

	public:
		virtual int size(void) const = 0;

	public:
		virtual const Object& first(void) const = 0;
		virtual const Object& last(void) const = 0;
	};

	template <typename Object>
	class IDoubleLinkList
	{
	public:
		virtual void append(const Object& obj) = 0;
		virtual void prepend(const Object& obj) = 0;
		virtual void clear(void) = 0;
		virtual void insertAfter(const Object& obj, const Object& after) = 0;
		virtual void insertBefore(const Object& obj, const Object& before) = 0;
		virtual void remove(const Object& obj) = 0;

	public:
		virtual bool isEmpty(void) const = 0;

	public:
		virtual int size(void) const = 0;

	public:
		virtual const Object& first(void) const = 0;
		virtual const Object& last(void) const = 0;
	};
}




#endif
