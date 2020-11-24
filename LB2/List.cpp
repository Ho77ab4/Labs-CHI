#include "List.h"
#include <assert.h>

template<class T, size_t N>
List<T, N>::List()
{
	array = new T[N];
	s = 0;
}

template<class T, size_t N>
List<T, N>::~List()
{
	delete[] array;
	array = nullptr;
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
