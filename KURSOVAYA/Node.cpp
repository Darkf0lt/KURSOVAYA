#include "Node.h"

Node* List::Add(student st)
{
    Node* node = NULL;
    Node* elem = new Node();
    elem->field = st;
    count++;
    if (node == NULL) // Добавление нового корня
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
    elem->ptr = node->ptr; // Добавление узла после текущего
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