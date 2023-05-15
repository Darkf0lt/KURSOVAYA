#pragma once
#include "student.h"
#include <iostream>
using namespace std;
class Node
{
	student field;
	Node* ptr;
	friend class List;
};

class List
{
	Node* head;   
	int count = 0; 
public:
	Node* Next(Node*);
	List() { head = NULL; } 
	bool isEmpty() { return head == NULL; }  
	student getValue(Node* p) { return p->field; } 
	void setValue(Node* p, student val) { p->field = val; } 
	void Clear();         
	Node* Add(student st);    
	void Print();
	void Print(int param);
};
