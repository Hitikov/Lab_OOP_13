#pragma once
#include "Pair.h"

//перегрузка операции присваивания
Pair::Pair() {
	first = 0;
	second = 0;
}
Pair::Pair(int f = 0, double s = 0) {
	this->first = f;
	this->second = s;
}
Pair::Pair(const Pair& p) {
	this->first = p.first;
	this->second = p.second;
}
Pair::~Pair() {
}
int Pair::getFirst() { return this->first; }
void Pair::SetFirst(int x) { this->first = x; }
double Pair::getSecond() { return this->second; }
void Pair::SetSecond(double y) { this->second = y; }
void Pair::print() {
	cout << this->first << " : " << this->second << endl;
}

//перегруженные операции 
Pair Pair::operator+(const int& x) const {
	return Pair(this->first + x, this->second);
}
Pair Pair::operator+(const double& y) const {
	return Pair(this->first, this->second + y);
}
Pair Pair::operator+(const Pair& p) const {
	return Pair(this->first + p.first, this->second + p.second);
}
Pair Pair::operator-(const Pair& p) const {
	return Pair(this->first - p.first, this->second - p.second);
}
Pair Pair::operator=(const Pair& p) {
	this->first = p.first;
	this->second = p.second;
	return *this;
}


bool Pair::operator> (const Pair& p) {
	if (this->first > p.first && this->second > p.second || 
		this->first + this->second > p.first + p.second ||
		this->first > p.first + p.second ||
		this->second > p.first + p.second) {
		return true;
	}
	return false;
}
bool Pair::operator< (const Pair& p )
{
	if (this->first < p.first && this->second < p.second ||
		p.first + p.second > this->first + this->second ||
		p.first > this->first + this->second ||
		p.second > this->first + this->second) {
		return true;
	}
	return false;
}

//Дружественные перегруженные операции
Pair operator+(const int& x, const Pair& p) {
	return p + x;
}
Pair operator+(const double& y, const Pair& p) {
	return p + y;
}
ostream& operator<<(ostream& str, const Pair& p) {
	str << " " << p.first << " : " << p.second;
	return str;
}

istream& operator>>(istream& str, Pair& p) {
	cout << "Enter int value: ";
	str >> p.first;
	cout << "Enter double value: ";
	str >> p.second;
	return str;
}