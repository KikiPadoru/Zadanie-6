#include <iostream>
#include <stdlib.h>
#include "Znak.h"
#include "garland.h"

int main()
{

    int a;
    ifstream in("text.txt");
    in >> a;
    Garland<Znak>A;
    Znak s;
    cout << "\033[7;33mOriginal file:\033[0m" << endl;
    for (int i = 0; i < a; i++) {
        in >> s;
        A.push_back(s);
    }
    A.Print(0);
    cout << "\n\033[7;33mPerevernem:\033[0m" << endl;
    A.coup();
    A.Print(1);
    int color=0;
    cout << "\n\033[7;31mSortirovka ne polu4ilas\033[0m" << endl;
    cout << "\033[7;31mOna tam zakamentirovana\033[0m" << endl;
    
    cout << "\033[7;34mYa ne znay rabotaet li no vvedide ot 0-5:\033[0m" << endl;
    cin >> color;
    A.Print(color);
    //for (int i = 0; i < a; i++) {
    //    in >> A[i];
    //    cout << A[i];
    //}
    //Znak* A1 = A;
    //Znak* A2 = A;
    //Znak* A3 = A;
    //Znak* A4 = A;
    //Znak* A5 = A;

    //cout << endl;
    //cout << "BubbleSort:" << endl; //пузырьком
    //Znak::BubbleSort(A1, a);

    //for (int i = 0; i < a; i++) {
    //    cout << A1[i];
    //}

    //cout << endl;
    //cout << "InsertSort:" << endl;//вставками
    //Znak::InsertSort(A2, a);
    //for (int i = 0; i < a; i++) {
    //    cout << A2[i];
    //}

    //cout << endl;
    //cout << "ChoiceSort:" << endl;//выбором
    //Znak::ChoiceSort(A3, a);
    //for (int i = 0; i < a; i++) {
    //    cout << A3[i];
    //}

    //cout << endl;
    //cout << "ShellSort:" << endl;//шелла
    //Znak::ShellSort(A4, a);
    //for (int i = 0; i < a; i++) {
    //    cout << A4[i];
    //}

    //cout << endl;
    //cout << "hoarasort:" << endl;//хоара
    //Znak::hoarasort(A5, 0, a - 1);
    //for (int i = 0; i < a; i++) {
    //    cout << A5[i];
    //}
    ///*  int O[5] = { 2,1,5,3,4 };
    //  hoarasort(O, 0, 4);
    //  for (int i = 0; i < 5; i++) {
    //      cout << O[i];
    //  }*/

    //cout << endl;
    //cout << "Qsort:" << endl;//Qsort
    //qsort(A, a, sizeof(Znak), Znak::comp);
    //for (int i = 0; i < a; i++) {
    //    cout << A[i];
    //}
}