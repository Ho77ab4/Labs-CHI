#include <assert.h>

#pragma once
template<class T, size_t N>
class List
{
private:
	T array[N];
	int s;

public:
	List();
	size_t size() const;
	const T& operator [] (int index) const;
	void operator += (const T&);
};

template<class T, size_t N>
List<T, N>::List()
{
	s = 0;
}

template<class T, size_t N>
size_t List<T, N>::size() const
{
	return size_t(s);
}

template<class T, size_t N>
const T & List<T, N>::operator[](int index) const
{
	assert(index >= 0 && index < N);

	return array[index];
}

template<class T, size_t N>
void List<T, N>::operator+=(const T& item)
{
	array[s] = item;
	s++;
}


