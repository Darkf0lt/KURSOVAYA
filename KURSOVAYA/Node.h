#pragma once
#include "student.h"
#include <iostream>
using namespace std;
class Node
{
	student field;
	class Node* ptr;
	friend class List;
};

class List
{
	Node* head;    // ������ ������
	int count = 0; // ���������� ����� ������
	Node* Prev(Node*); // ������� � ����������� ���� (�� ������������ �����)
public:
	List() { head = NULL; } // ������������� ������
	int getCount() { return count; } // ��������� ���������� ����� ������
	bool isEmpty() { return head == NULL; }  // ��������, ���� �� ������
	student getValue(Node* p) { return p->field; } // ��������� �������� ���� ������
	void setValue(Node* p, student val) { p->field = val; } // ��������� �������� ���� ������
	Node* getFirst() { return head; } // ��������� ��������� ���� ������
	Node* getLast();      // ��������� ���������� ���� ������
	void Clear();        // ������� ������
	Node* Next(Node*);      // ������� � ���������� ����
	Node* Add(student st, Node*);    // ���������� ���� ������
	Node* Delete(Node*);    // �������� ���� ������
	void Print();        // ����� �������� ����� ������
	void Swap(Node*, Node*);  // ����������� ���� �����
};
