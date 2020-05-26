#include "Znak.h"

void Znak::copu(int* a)
{

	data[0] = a[0];
	data[1] = a[1];
	data[2] = a[2];

}

int Znak::Sum()
{
	return data[2] * 10000 + data[1] * 100 + data[0];
}

bool Znak::operator==(Znak& a)
{
	return Sum() == a.Sum();
}
bool Znak::operator>(Znak& a)
{
	return Sum() > a.Sum();
}

bool Znak::operator<(Znak& a)
{
	return Sum() < a.Sum();
}

Znak::Znak() {
	name = "";
	zn = "";
}
Znak::Znak(Znak& a) {
	name = a.name;
	zn = a.zn;
	int* b = (int*)a.data;
	copu(b);

}
void Znak::BubbleSort(Znak* a, int n)
{
	Znak t;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1]) { flag = true; t = a[i]; a[i] = a[i + 1]; a[i + 1] = t; }

	}
}
void Znak::InsertSort(Znak* x, int n)
{
	Znak t;
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && x[j - 1] > x[j]; j--) {
			t = x[j - 1]; x[j - 1] = x[j]; x[j] = t;
		}
}
void Znak::ChoiceSort(Znak* x, int n)
{
	Znak min;
	for (int i = 0; i < n; i++) {
		min = x[i];
		for (int j = i + 1; j<n && min > x[j]; j++)min = x[j];
		x[i] = min;
	}
}
void Znak::ShellSort(Znak* a, int size)
{
	int step = size / 2;//číčöčŕëčçčđóĺě řŕă.
	while (step > 0)//ďîęŕ řŕă íĺ 0
	{
		for (int i = 0; i < (size - step); i++) {
			for (int j = i; j >= 0 && a[j] > a[j + step]; j--)
			{
				Znak temp = a[j];
				a[j] = a[j + step];
				a[j + step] = temp;
			}
		}
		step /= 2;//óěĺíüřŕĺě řŕă
	}
}
void Znak::hoarasort(Znak* mas, int first, int last)
{
	Znak mid;
	Znak count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //âű÷čńëĺíčĺ îďîđíîăî ýëĺěĺíňŕ
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) //ďĺđĺńňŕíîâęŕ ýëĺěĺíňîâ
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) Znak::hoarasort(mas, first, l);
	if (f < last) Znak::hoarasort(mas, f, last);
}
int Znak::comp(const void* a, const void* b)
{
	Znak A = *((Znak*)a);
	Znak B = *((Znak*)b);
	if (A > B)return(1);
	if (A == B)return(0);
	return(-1);
}
istream& operator >>(istream& in, Znak& a) {
	in >> a.name >> a.zn >> a.data[0] >> a.data[1] >> a.data[2];
	return in;
}

ostream& operator<<(ostream& on, Znak& a) {
	return on << a.name << " " << a.zn << " " << a.data[0] << " " << a.data[1] << " " << a.data[2] << " " << endl;
}