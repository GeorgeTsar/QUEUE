#include <iostream>
#include "Queue.h"
using namespace std;

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� �����
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
	// �������� ������ ���� (node)
	Node* temp = new Node;

	// ���������� �������
	temp->data = data;
	// ��������� ���� �����������
	temp->Next = NULL;
	// ����� ���� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) 
	{
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ���� ���������� ������������
	// ���� �� ������ �����������
	else 
	{
		Head = Tail = temp;
	}
	Count++;
}

void List::Del()
{
	// ���������� ����� ��������� ����
	Node* temp = Head;
	// ������������� ������ �� ��������� ����
	Head = Head->Next;
	// ������� ������ �������� ����
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
			help = temp; // ���������� �������� temp
			temp = temp->Next;
		}
		if (temp == Head) // ���� ����, ������� ���� �������, ������
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
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Node* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}

