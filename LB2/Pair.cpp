#include "Pair.h"

template<class A, class B>
Pair<A, B>::Pair()
{
	key = nullptr;
	value = nullptr;
}

template<class A, class B>
Pair<A, B>::~Pair()
{
	key = nullptr;
	value = nullptr;
}

template<class A, class B>
Pair<A, B>::Pair(const A & k, const B & v)
{
	key = k;
	value = v;
}

template<class A, class B>
const A & Pair<A, B>::getKey() const
{
	return key;
}

template<class A, class B>
const B & Pair<A, B>::getValue() const
{
	return value;
}
