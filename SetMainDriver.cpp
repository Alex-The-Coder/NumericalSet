#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Set.h"
using namespace std;

Set buildTestSet(int);

int main()
{
	srand(time(NULL));

	cout << "Set 1:" << endl;
	Set set1 = buildTestSet(12);

	cout << "Set 2:" << endl;
	Set set2 = buildTestSet(5);
	cout << endl;

	cout << "Intersection: ";
	set1.getIntersection(set2).printOut();
	cout << "Union: ";
	set1.getUnion(set2).printOut();
	cout << endl;

	cout << "Set 1 Equals Set 1: " << set1.equals(set1) << endl;
	cout << "Set 1 Equals Set 2: " << set1.equals(set2) << endl << endl;

	cout << "Set 1 Contains -1 (Before Insert): " << set1.contains(-1) << endl;
	set1.addItem(-1);
	cout << "Set 1 Contains -1 (After Insert): " << set1.contains(-1) << endl << endl;

	cout << "Adding -5, -10, -15 and -20 to Set 1" << endl;
	set1.addItem(-5);
	set1.addItem(-10);
	set1.addItem(-15);
	set1.addItem(-20);

	cout << "Set 1 Before Remove -1: ";
	set1.printOut();
	set1.remove(-1);
	cout << "Set 1 After Remove -1: ";
	set1.printOut();
	cout << endl;

	cout << "Creating Empty Set" << endl;
	Set empty;
	cout << "Set 1 isEmpty: " << set1.isEmpty() << endl;
	cout << "Empty Set isEmpty: " << empty.isEmpty() << endl << endl;

	cout << "Creating Set for Size Test" << endl;
	Set sizeLimit;
	cout << "Starting Size: " << sizeLimit.size() << endl;
	cout << "Adding 105 Elements" << endl;
	for (int i = 0; i < 105; i++)
	{
		sizeLimit.addItem(i);
	}
	cout << "Ending Size: " << sizeLimit.size() << endl;

	return 0;
}

// Builds a Set supplied with *amount* random numbers (ignoring duplicates)
Set buildTestSet(int amount)
{
	Set set;

	cout << "Generated Numbers: [ ";

	for (int i = 0; i < amount; i++)
	{
		int generated = rand() % amount;
		set.addItem(generated);
		cout << generated << ' ';
	}

	cout << ']' << endl;
	cout << "Resulting Set: ";
	set.printOut();

	return set;
}
