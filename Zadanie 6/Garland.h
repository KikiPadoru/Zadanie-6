#pragma once
#include <iostream>
using namespace std;
template<typename T>
class Garland
{
public:
	Garland();
	~Garland();
	void pop_front();//Udalenie pervogo
	void push_back(T data);//Dobavlenie v konez
	void clear();// очистить список
	int sizeElement() { return Kol; }// koli4estvo elementov
	T& operator[](const int index);// peregruzka[]
	void push_front(T data);//dobavit v na4alo
	void insert(T data, int index);//dobavlenie elementa po indexsu
	void removeAt(int index);//Udalenie po indexu
	void pop_back();//Udalenie poslednego elementa v massive
	void Print(int a);//Vivod vsego masiva, s collor
	void coup();//Perevorot
	//void sort(); //Nepolu4ilas
private:


	template<typename T>
	class Bulbs
	{
	public:
		T data;
		Bulbs* Next;
		Bulbs(T data = T(), Bulbs* Next = nullptr)
		{
			this->data = data;
			this->Next = Next;
		}
	};
	int Kol;
	Bulbs<T>* first;

	Bulbs<T>* Nomer(int index) {
		int counter = 0;

		Bulbs<T>* current = this->first;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->Next;
			}
			current = current->Next;
			counter++;
		}
		return this->first;
	}
};
template<typename T>
Garland<T>::Garland()
{
	Kol = 0;
	first = nullptr;
}


template<typename T>
Garland<T>::~Garland()
{
	clear();
}

template<typename T>
void Garland<T>::pop_front()
{
	Bulbs<T>* temp = first;

	first = first->Next;

	delete temp;

	Kol--;

}

template<typename T>
void Garland<T>::push_back(T data)
{
	if (first == nullptr)
	{
		first = new Bulbs<T>(data);
	}
	else
	{
		Bulbs<T>* current = this->first;

		while (current->Next != nullptr)
		{
			current = current->Next;
		}
		current->Next = new Bulbs<T>(data);

	}

	Kol++;
}

template<typename T>
void Garland<T>::clear()
{
	while (Kol)
	{
		pop_front();
	}
}


template<typename T>
T& Garland<T>::operator[](const int index)
{
	int counter = 0;

	Bulbs<T>* current = this->first;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->Next;
		counter++;
	}
}

template<typename T>
void Garland<T>::push_front(T data)
{
	first = new Bulbs<T>(data, first);
	Kol++;
}

template<typename T>
void Garland<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Bulbs<T>* previous = this->first;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->Next;
		}

		Bulbs<T>* newNode = new Bulbs<T>(data, previous->Next);

		previous->Next = newNode;

		Kol++;
	}


}

template<class T>
void Garland<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Bulbs<T>* previous = this->first;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->Next;
		}


		Bulbs<T>* toDelete = previous->Next;
		previous->Next = toDelete->Next;
		delete toDelete;
		Kol--;
	}

} 
template<typename T>
void Garland<T>::pop_back()
{
	removeAt(Kol - 1);
}

template<typename T>
void Garland<T>::Print(int a)
{
	char Collor[6][8]  = {"\033[1;30m", "\033[2;31m","\033[2;32m","\033[2;33m","\033[2;34m","\033[2;35m" };
	int counter = 0;
	Bulbs<T>* current = this->first;
	cout << Collor[a];
	while (current != nullptr)
	{
		cout << current->data << ' ';;
		current = current->Next;
		counter++;
	}
	cout << "\033[0m" << endl;
}

//template<class T>    Сортировка не получилась Nepolu4ilas
//void Garland<T>::sort()
//{
//	for (int i = 1; i < sizeElement(); i++) {
//		Bulbs<T>* ly = Nomer(i-1);
//		removeAt(i);
//		int j;
//		for (j = i - 1; j >= 0 && j > ly->data; j--);
//		insert(ly->data,j+1);
//	}
//}
//6 Variant
//template<typename T>
//void Garland<T>::coup() {
//	int ko = Kol-1;
//	Bulbs<T>* current = this->first;
//	Bulbs<T>* c = this->first;
//	
//	first->Next = Nomer(2);
//	for (int i = 0; 0 < ko; i++) {
//	/*	Bulbs<T>* cur = Nomer(i - 2);
//		Bulbs<T>* current = this->first;*/
//		if (i == 0)first = nullptr;
//		current = this->current;
//		if(i > 1)this->current = Nomer(i-2);
//	}
//}
//6 Variant 
template<typename T>
void Garland<T>::coup() {
	int End = Kol - 1;
	Bulbs<T>* start = this->first;
	Bulbs<T>* finish = Nomer(End - 1); //ссылка на последний элемент
	/*cout << "\033[2;31m" << start->data << "\033[0m";
	cout << "\033[2;33m" << finish->data << "\033[0m";*/
	Bulbs<T>* f1;
	Bulbs<T>* f2 = Nomer(End - 1);
	for (int i = End - 1; i >= 1; i--) {
		f1 = Nomer(i);
		f2 = Nomer(i - 1);
		f1->Next = f2;
		/*cout << "\033[2;33m" << f1->data << "\033[0m";*/
	}
	f2->Next = start;
	this->first = finish;
	start->Next = nullptr;



	//Bulbs<T>* p2;
	//Bulbs<T>* prev_p2=first;
	//Bulbs<T>* tmp_pos;
	//cout << "\033[2;31m" << "\033[0m";
	//for (int i = 0; i < Per; i++) {
	//	prev_p2 = prev_p2->Next;
	//	cout << "\033[2;31m" << prev_p2->data << "\033[0m";
	//}
	//p2 = prev_p2->Next;
	//for (int i = 0; i < Vto; i++) {
	//	prev_p1 = prev_p1->Next;
	//	cout << "\033[2;31m" << prev_p1->data << "\033[0m";
	//}
	//p1 = prev_p1->Next;

	///*cout <<"\033[2;31m"<< p2->data <<"\033[0m";
	//cout << "\033[2;33m" << p1->data << "\033[0m";*/

	//tmp_pos = p2->Next;
	//p2->Next = p1->Next;
	//p1->Next = tmp_pos;
	//	prev_p2->Next = p1;
	//	prev_p1->Next = p2;
}
