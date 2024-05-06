#include "Pair.h"
#include "Tasks.h"

#include <iostream>
#include <functional>
#include <algorithm>
#include <random>
#include <map>

using namespace std;

Pair MrandomPair() {
	int a = rand() % 1000;
	double b = rand() % 100000 * 0.01;
	Pair newPair;
	newPair.SetFirst(a);
	newPair.SetSecond(b);
	return newPair;
}

ostream& operator<<(ostream& stream, pair<int, Pair> p) {
	stream << "Key: " << p.first << endl << "Value: " << p.second << endl;
	return stream;
}

ostream& operator<<(ostream& stream, map<int, Pair> m) {
	map<int, Pair>::const_iterator iter = m.begin();
	while (iter != m.end()) {
		stream << *iter++;
	}
	return stream;
}

void generateMap(map<int, Pair>& m, int sizeVal) {
	for (int i = 0; i < sizeVal; i++) {
		Pair p = MrandomPair();
		m[p.getFirst()] = p;
	}
}

void rangeRemove(map<int, Pair>& m, int lowLim, int highLim) {
	map<int, Pair>::iterator iter = m.begin();
	int key;
	while (iter != m.end()) {
		key = iter->first;
		if (!(key > lowLim && key < highLim)) {
			++iter;
		}
		else {
			iter = m.erase(iter);
		}
	}
}

int funk_task3() {
	int sizeVal;

	//Creating
	do {
		cout << "Enter map size: ";
		cin >> sizeVal;
	} while (sizeVal < 1);

	map<int, Pair> map1;

	generateMap(map1, sizeVal);
	cout << "Map generated:\n" << map1 << endl;

	//Sorting

	//Map cannot be sorted

	//Min max values search + sum of all

	int maxIntVal = map1.begin()->second.getFirst(), minIntVal = map1.begin()->second.getFirst();
	double maxDoubleVal = map1.begin()->second.getSecond(), minDoubleVal = map1.begin()->second.getSecond();
	Pair midArifm, addPair;

	for_each(map1.begin(), map1.end(),
		[&midArifm, &maxIntVal, &minIntVal, &maxDoubleVal, &minDoubleVal](pair<int, Pair> p) {
			midArifm = midArifm + p.second;
			if (p.second.getFirst() > maxIntVal) maxIntVal = p.second.getFirst();
			if (p.second.getFirst() < minIntVal) minIntVal = p.second.getFirst();
			if (p.second.getSecond() > maxIntVal) maxDoubleVal = p.second.getSecond();
			if (p.second.getSecond() < minIntVal) minDoubleVal = p.second.getSecond();
		});

	addPair.SetFirst(minIntVal + maxIntVal);
	addPair.SetSecond(minDoubleVal + maxDoubleVal);

	midArifm.SetFirst(midArifm.getFirst() / sizeVal);
	midArifm.SetSecond(midArifm.getSecond() / sizeVal);

	map1[midArifm.getFirst()] = midArifm;

	cout << "Map's arithmetical mean:\n" << midArifm << endl;

	cout << "Map after adding arithmetical mean:\n" << map1 << endl;

	double lowLim, highLim;

	//Deleting
	cout << "Enter value range for deleting:\n";
	cout << "Lower limit: ";
	cin >> lowLim;
	cout << "Higher limit: ";
	cin >> highLim;
	if (lowLim > highLim) swap(lowLim, highLim);

	rangeRemove(map1, lowLim, highLim);

	if (map1.size() == 0) {
		cout << "Map is empty" << endl;
		return 0;
	}
	cout << "Map after clearing:\n" << map1 << endl;

	//MinMax applying
	cout << "Sum of min and max elements: " << addPair << endl;

	for_each(map1.begin(), map1.end(), [&map1, addPair](pair<int, Pair> p) {map1[p.first] = p.second + addPair; });

	cout << "Map after adding sum of elements:\n" << map1 << endl;

	//Search
	cout << "Enter search key (int): ";
	cin >> sizeVal;

	auto tempPair = find_if(map1.begin(), map1.end(),
		[sizeVal](pair<int, Pair> p) {
			return sizeVal == p.first;
		});

	if (tempPair != map1.end()) {
		cout << "Found pair: " << tempPair->second << endl;
	}
	else {
		cout << "Pair not found" << endl;
	}

	return 0;
}