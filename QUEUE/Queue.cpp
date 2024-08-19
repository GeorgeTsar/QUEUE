#include <iostream>
#include "Queue.h"
using namespace std;

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество узлов
	return Count;
}

int List::GetInd(char a)
{
	Node* temp = Head;
	for (int i = 0; i < Count; i++)
	{
		if (temp->data == a)
		{
			return i;
		}
		temp = temp->Next;
	}
	return 0;  // Not found
}

void List::Add(char data)
{
	// Создание нового узла (node)
	Node* temp = new Node;

	// Заполнение данными
	temp->data = data;
	// Следующий узел отсутствует
	temp->Next = NULL;
	// Новый узел становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) 
	{
		Tail->Next = temp;
		Tail = temp;
	}
	// новый узел становится единственным
	// если он первый добавленный
	else 
	{
		Head = Tail = temp;
	}
	Count++;
}

void List::Del()
{
	// Запоминаем адрес головного узла
	Node* temp = Head;
	// Перебрасываем голову на следующий узел
	Head = Head->Next;
	// Удаляем бывший головной узел
	delete temp;
}

void List::DelInd(int index)
{
	if ((Head != NULL) && (index < Count) && (index >= 0))  
	{
		Node* temp = Head;
		Node* help = Head;

		for (int i = 0; i < index; i++)
		{
			help = temp; // Предыдущее значение temp
			temp = temp->Next;
		}
		if (temp == Head) // Если узел, который надо удалить, первый
		{
			Head = temp->Next;
		}
		else
		{
			help->Next = temp->Next;
		}
		Count--; 
	}
}

void List::DelEnd()
{
	if (!Head)
		return;

	if (!Head->Next)
	{
		delete Head;
		Head = nullptr;
		return;
	}

	Node* temp = Head;
	while (temp->Next->Next)
	{
		temp = temp->Next;
	}

	delete temp->Next;
	temp->Next = nullptr;
	Count--;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Node* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}

