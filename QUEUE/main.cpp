#include "Queue.h"
#include <iostream>
using namespace std;


// Тестовый пример
void main()
{
	// Создаём объект класса List
	List lst;
	lst.Add('A');
	lst.Add('B');
	lst.Add('C');
	lst.Add('D');
	lst.Add('E');
	lst.Add('F');
	lst.Print();

	lst.AddIndex('Z', 2);
	lst.Print();
	cout << lst.GetCount() << endl << endl;

	lst.DelInd(2);
	lst.Print();
	cout << lst.GetCount() << endl << endl;

	lst.DelEnd();
	lst.Print();
	cout << lst.GetCount() << endl << endl;

	cout << lst.GetInd('C') << endl;
}