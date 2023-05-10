#include "Node.h"

Node* List::Add(student st)
{
    Node* node = NULL;
    Node* elem = new Node();
    elem->field = st;
    count++;
    if (node == NULL) 
    {
        if (head == NULL) {
            elem->ptr = NULL;
            head = elem;
        }
        else {
            elem->ptr = head;
            head = elem;
        }
        return elem;
    }
    elem->ptr = node->ptr; 
    node->ptr = elem;
    return elem;
}


Node* List::Next(Node* node)
{
    if (isEmpty()) return NULL;
    return node->ptr;
}

Node* List::Prev(Node* node)
{
    if (isEmpty()) return NULL;
    if (node == head) return NULL;
    Node* p = head;
    while (p->ptr != node)
        p = p->ptr;
    return p;
}


void List::Clear()
{
    class Node* p = head;
    if (p == NULL) return;
    do {
        Node* d = p;
        p = Next(p);
        delete d;
    } while (p != NULL);
    count = 0;
    head = NULL;
}

void List::Print()
{
    if (isEmpty()) { cout << "Список пуст" << endl; return; }
    Node* p = head;
    while (p != NULL) 
    {
        student tmpst = getValue(p);
        tmpst.PrintInfo();
        cout << "|-----------------------------------------------------------------------------|"<<endl;
        p = Next(p);
    } ;
    cout << endl;
}

bool LookForArr(int k, int* arr, int start)
{
    for (int i = start; i < sizeof(arr); i++)
    {
        if (k == arr[i]) return true;
    }
    return false;
}

void List::Print(int param)
{
    if (isEmpty()) { cout << "Таких студентов не существует" << endl; system("pause"); return; }
    Node* p = head;
    bool marks2 = false, printed = false;
    int mark1, mark2;
    switch (param)
    {
    case 1:
        mark1 = 3;
        break;
    case 2:
        mark1 = 3;
        mark2 = 4;
        marks2 = true;
        break;
    case 3:
        mark1 = 5;
        break;
    }

    if (!marks2)
    {
        while (p != NULL)
        {
            student tmpst = getValue(p);
            if (!LookForArr(mark1, tmpst.GetMarks(), 1))
            {
                tmpst.PrintInfo();
                cout << "|-----------------------------------------------------------------------------|" << endl;
                printed = true;
            }
            p = Next(p);
        };
    }
    else
    {
        while (p != NULL)
        {
            student tmpst = getValue(p);
            if (!LookForArr(mark1, tmpst.GetMarks(), 1) && !LookForArr(mark2, tmpst.GetMarks(), 1))
            {
                tmpst.PrintInfo();
                cout << "|-----------------------------------------------------------------------------|" << endl;
                printed = true;
            }
            p = Next(p);
        };
    }
    if (!printed)
    {
        cout << "Таких студентов не существует" << endl;
    }
    system("pause");
}