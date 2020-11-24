#pragma once
template<class A, class B>
class Pair
{
private:
	A key;
	B value;

public:
	Pair();
	Pair(const A&, const B&);
	const A& getKey() const;
	const B& getValue() const;
};

template<class A, class B>
Pair<A, B>::Pair()
{
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

