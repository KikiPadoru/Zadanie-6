#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Znak
{
public:

	string name;
	string zn;
	int col;
	int data[3];//äàòà
	void copu(int* a);
	int Sum();
	bool operator ==(Znak& a);
	bool operator >(Znak& a);
	bool operator <(Znak& a);

	Znak();
	Znak(Znak& a);
	Znak(const Znak& a);
	static void BubbleSort(Znak* a, int n);
	static void InsertSort(Znak* x, int n);
	static void ChoiceSort(Znak* x, int n);
	static void ShellSort(Znak* a, int size);
	static void hoarasort(Znak* mas, int first, int last);
	static int comp(const void* a, const void* b);
	friend istream& operator >> (istream& in, Znak& a);
	friend ostream& operator << (ostream& on, Znak& a);

};

