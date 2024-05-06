#include "Pair.h"
#include "Tasks.h"

#include <iostream>
#include <functional>
#include <algorithm>
#include <random>
#include <list>

using namespace std;

Pair LrandomPair() {
	int a = rand() % 1000;
	double b = rand() % 100000 * 0.01;
	Pair newPair;
	newPair.SetFirst(a);
	newPair.SetSecond(b);
	return newPair;
}

ostream& operator<<(ostream& stream, list<Pair>& l) {
	for_each(l.begin(), l.end(), [](Pair& p) {cout << p << endl; });
	return stream;
}

int funk_task1() {
	int sizeVal;

	do {
		cout << "Enter list size: ";
		cin >> sizeVal;
	} while (sizeVal < 1);

	list<Pair> list1(sizeVal);

	generate(list1.begin(), list1.end(), LrandomPair);
	cout << "List generated:\n" << list1 << endl;

	int maxIntVal = list1.begin()->getFirst(), minIntVal = list1.begin()->getFirst();
	double maxDoubleVal = list1.begin()->getSecond(), minDoubleVal = list1.begin()->getSecond();
	Pair midArifm, addPair;

	list1.sort();

	cout << "List sorted:\n" << list1 << endl;

	list1.sort([](Pair& a, Pair& b) {return a > b; });

	cout << "Reverse sort:\n" << list1 << endl;

	for_each(list1.begin(), list1.end(),
		[&midArifm, &maxIntVal, &minIntVal, &maxDoubleVal, &minDoubleVal](Pair& p) {
			midArifm = midArifm + p;
			if (p.getFirst() > maxIntVal) maxIntVal = p.getFirst();
			if (p.getFirst() < minIntVal) minIntVal = p.getFirst();
			if (p.getSecond() > maxIntVal) maxDoubleVal = p.getSecond();
			if (p.getSecond() < minIntVal) minDoubleVal = p.getSecond();
		});

	midArifm.SetFirst(midArifm.getFirst() / sizeVal);
	midArifm.SetSecond(midArifm.getSecond() / sizeVal);

	addPair.SetFirst(minIntVal + maxIntVal);
	addPair.SetSecond(minDoubleVal + maxDoubleVal);

	list1.push_back(midArifm);

	cout << "List's arithmetical mean:\n" << midArifm << endl;

	cout << "List after adding arithmetical mean:\n" << list1 << endl;

	double lowLim, highLim;

	cout << "Enter value range for deleting:\n";
	cout << "Lower limit: ";
	cin >> lowLim;
	cout << "Higher limit: ";
	cin >> highLim;
	if (lowLim > highLim) swap(lowLim, highLim);

	list<Pair>::iterator iter = remove_if(list1.begin(), list1.end(),
		[lowLim, highLim](Pair& p) {
			return p.getFirst() + p.getSecond() > lowLim && p.getFirst() + p.getSecond() < highLim;
		});
	list1.erase(iter, list1.end());

	if (list1.size() == 0) {
		cout << "List is empty" << endl;
		return 0;
	}
	cout << "List after clearing:\n" << list1 << endl;

	cout << "Sum of min and max elements: " << addPair << endl;
	for_each(list1.begin(), list1.end(), [addPair](Pair& p) {p = p + addPair; });
	cout << "List after adding sum of elements:\n" << list1 << endl;

	cout << "Enter search key (int): ";
	cin >> sizeVal;

	auto tempPair = find_if(list1.begin(), list1.end(),
		[sizeVal](Pair& p) {
			return sizeVal == p.getFirst();
		});

	if (tempPair != list1.end()) {
		cout << "Found pair: " << *tempPair << endl;
	}
	else {
		cout << "Pair not found" << endl;
	}

	return 0;
}