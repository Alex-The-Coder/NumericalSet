#ifndef SET_H_
#define SET_H_

#include <vector>
using namespace std;

class Set
{
private:
	vector<int> elements;
public:
	void addItem(int element);
	bool contains(int element);
	bool isEmpty();
	void remove(int element);
	bool equals(Set& set);
	unsigned int size();
	Set getIntersection(Set& set);
	Set getUnion(Set& set);

	void printOut();
};

#endif /* SET_H_ */
