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
	Node* head;    // Корень списка
	int count = 0; // Количество узлов списка
	Node* Prev(Node*); // Переход к предыдущему узлу (не интерфейсный метод)
public:
	List() { head = NULL; } // Инициализация списка
	int getCount() { return count; } // Получение количества узлов списка
	bool isEmpty() { return head == NULL; }  // Проверка, пуст ли список
	student getValue(Node* p) { return p->field; } // Получение значения узла списка
	void setValue(Node* p, student val) { p->field = val; } // Установка значения узла списка
	Node* getFirst() { return head; } // Получение корневого узла списка
	Node* getLast();      // Получение последнего узла списка
	void Clear();        // Очистка списка
	Node* Next(Node*);      // Переход к следующему узлу
	Node* Add(student st, Node*);    // Добавление узла списка
	Node* Delete(Node*);    // Удаление узла списка
	void Print();        // Вывод значений узлов списка
	void Swap(Node*, Node*);  // Взаимообмен двух узлов
};
