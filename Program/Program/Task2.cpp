#include "Pair.h"
#include "Tasks.h"

#include <iostream>
#include <functional>
#include <algorithm>
#include <random>
#include <queue>

using namespace std;

class GreaterThanPair {
public:
	bool operator()(Pair a, Pair b) {
		return a > b;
	}
};

Pair QrandomPair() {
	int a = rand() % 1000;
	double b = rand() % 100000 * 0.01;
	Pair newPair;
	newPair.SetFirst(a);
	newPair.SetSecond(b);
	return newPair;
}

ostream& operator<<(ostream& stream, priority_queue<Pair, vector<Pair>, GreaterThanPair> q) {
	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
	return stream;
}

void generateQueue(priority_queue<Pair, vector<Pair>, GreaterThanPair>& q, int sizeVal) {
	for (int i = 0; i < sizeVal; i++) {
		q.push(QrandomPair());
	}
}

void minmaxSearch(priority_queue<Pair, vector<Pair>, GreaterThanPair> q, Pair& midArifm, Pair& addPair) {
	Pair p = q.top();
	int maxIntVal = p.getFirst(), minIntVal = p.getFirst();
	double maxDoubleVal = p.getSecond(), minDoubleVal = p.getSecond();
	
	while (!q.empty()) {
		p = q.top();
		q.pop();
		midArifm = midArifm + p;
		if (p.getFirst() > maxIntVal) maxIntVal = p.getFirst();
		if (p.getFirst() < minIntVal) minIntVal = p.getFirst();
		if (p.getSecond() > maxIntVal) maxDoubleVal = p.getSecond();
		if (p.getSecond() < minIntVal) minDoubleVal = p.getSecond();
	}

	addPair.SetFirst(minIntVal + maxIntVal);
	addPair.SetSecond(minDoubleVal + maxDoubleVal);
}

void rangeRemove(priority_queue<Pair, vector<Pair>, GreaterThanPair>& q, int lowLim, int highLim) {
	priority_queue<Pair, vector<Pair>, GreaterThanPair> q1;
	while (!q.empty()) {
		Pair p = q.top();
		if (!(p.getFirst() + p.getSecond() > lowLim && p.getFirst() + p.getSecond() < highLim)) {
			q1.push(p);
		}
		q.pop();
	}
	q = q1;
}

void applyToAll(priority_queue<Pair, vector<Pair>, GreaterThanPair>& q, Pair addPair) {
	priority_queue<Pair, vector<Pair>, GreaterThanPair> q1;
	while (!q.empty()) {
		Pair p = q.top();
		q1.push(p + addPair);
		q.pop();
	}
	q = q1;
}

bool searchPair(priority_queue<Pair, vector<Pair>, GreaterThanPair> q, int key, Pair& tempPair) {
	while (!q.empty())
	{
		Pair p = q.top(); 
		q.pop();
		if (p.getFirst() == key) {
			tempPair = p;
			return true;
		}
	}
	return false;
}

int funk_task2() {
	int sizeVal;

	//Creating
	do {
		cout << "Enter queue size: ";
		cin >> sizeVal;
	} while (sizeVal < 1);

	priority_queue<Pair, vector<Pair>, GreaterThanPair> queue1;

	generateQueue(queue1, sizeVal);
	cout << "Queue generated:\n" << queue1 << endl;

	//Sorting

	//Queue cannot be sorted

	//Min max values search + sum of all

	
	Pair midArifm, addPair;
	minmaxSearch(queue1, midArifm, addPair);

	midArifm.SetFirst(midArifm.getFirst() / sizeVal);
	midArifm.SetSecond(midArifm.getSecond() / sizeVal);

	queue1.push(midArifm);

	cout << "Queue's arithmetical mean:\n" << midArifm << endl;

	cout << "Queue after adding arithmetical mean:\n" << queue1 << endl;

	double lowLim, highLim;

	//Deleting
	cout << "Enter value range for deleting:\n";
	cout << "Lower limit: ";
	cin >> lowLim;
	cout << "Higher limit: ";
	cin >> highLim;
	if (lowLim > highLim) swap(lowLim, highLim);

	rangeRemove(queue1, lowLim, highLim);

	if (queue1.size() == 0) {
		cout << "Queue is empty" << endl;
		return 0;
	}
	cout << "Queue after clearing:\n" << queue1 << endl;
	
	//MinMax applying
	cout << "Sum of min and max elements: " << addPair << endl;
	
	applyToAll(queue1, addPair);

	cout << "Queue after adding sum of elements:\n" << queue1 << endl;

	//Search
	cout << "Enter search key (int): ";
	cin >> sizeVal;
	
	Pair tempPair;

	if (searchPair(queue1, sizeVal, tempPair)) {
		cout << "Found pair: " << tempPair << endl;
	}
	else {
		cout << "Pair not found" << endl;
	}

	return 0;
}