#include <iostream>
#include "Set.h"

void Set::addItem(int element)
{
	int curSize = elements.size();

	if (curSize >= 100)
	{
		return;
	}

	if (contains(element))
	{
		return;
	}

	elements.push_back(element);
}

bool Set::contains(int element)
{
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		if (elements.at(i) == element)
		{
			return true;
		}
	}

	return false;
}

bool Set::isEmpty()
{
	return elements.size() == 0;
}

void Set::remove(int element)
{
	if (isEmpty())
	{
		return;
	}

	if (elements.back() == element)
	{
		elements.pop_back();
		return;
	}

	int index = -1;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		if (elements.at(i) == element)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		return;
	}

	elements.at(index) = elements.back();
	elements.pop_back();
}

bool Set::equals(Set& set)
{
	unsigned int size1 = elements.size();
	unsigned int size2 = set.elements.size();

	if (size1 != size2)
	{
		return false;
	}

	for (int i = 0; i < size1; i++)
	{
		if (!set.contains(elements.at(i)))
		{
			return false;
		}
	}

	return true;
}

unsigned int Set::size()
{
	return elements.size();
}

Set Set::getIntersection(Set& set)
{
	Set ret;

	for (unsigned int i = 0; i < elements.size(); i++)
	{
		if (set.contains(elements.at(i)))
		{
			ret.addItem(elements.at(i));
		}
	}

	for (unsigned int i = 0; i < set.elements.size(); i++)
	{
		if (contains(set.elements.at(i)))
		{
			ret.addItem(set.elements.at(i));
		}
	}

	return ret;
}

Set Set::getUnion(Set& set)
{
	Set ret;

	for (unsigned int i = 0; i < elements.size(); i++)
	{
		ret.addItem(elements.at(i));
	}

	for (unsigned int i = 0; i < set.elements.size(); i++)
	{
		ret.addItem(set.elements.at(i));
	}

	return ret;
}

void Set::printOut()
{
	if (isEmpty())
	{
		cout << "[]" << endl;
		return;
	}

	cout << "[ ";
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		cout << elements.at(i) << ' ';
	}
	cout << ']' << endl;
}
