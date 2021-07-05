#include "stapel.h"

#include "stapel_exception.h"

stapel::stapel(int size):data(new int[size]),size(size),index(0)
{
}

stapel::~stapel()
{
	delete[] data;
}

void stapel::push(int value)
{
	if (is_full())
		throw stapel_exception("Overflow");
	data[index++] = value;
}

int stapel::pop()
{
	if (is_empty())
		throw stapel_exception("Underflow");
	return data[--index];
}

bool stapel::is_empty() const
{
	return index <= 0;
}

bool stapel::is_full() const
{
	return index >= size;
}
