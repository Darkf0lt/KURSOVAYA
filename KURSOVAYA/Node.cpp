#include "Node.h"

Node* List::Add(student st, Node* node = NULL)
{
    Node* elem = new Node();
    elem->field = st;
    count++;
    if (node == NULL) // ���������� ������ �����
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
    elem->ptr = node->ptr; // ���������� ���� ����� ��������
    node->ptr = elem;
    return elem;
}

Node* List::Delete(Node* node)
{
    if (node == NULL) { return NULL; } // � ������ ��� �����
    count--;
    if (node == head)  // �������� ��������� ����
    {
        head = node->ptr;
        delete node;
        return head;
    }
    Node* prev = Prev(node); // �������� �������������� ����
    prev->ptr = node->ptr;
    delete node;
    return prev;
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

Node* List::getLast()
{
    Node* p = head;
    while (Next(p) != NULL)
        p = Next(p);
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
    if (isEmpty()) { cout << "������ ����" << endl; return; }
    Node* p = head;
    while (p != NULL) 
    {
        student tmpst = getValue(p);
        tmpst.PrintInfo();
        p = Next(p);
    } ;
    cout << endl;
}

void List::Swap(Node* node1, Node* node2)
{
    if (node1 == NULL || node2 == NULL) return; // �� ��������� ����� � �������������� �����
    if (node1 == node2) return; // ���� ���� ���� ������ ������, ������ ������ �� ����
    if (node2->ptr == node1) // ���� node2 ��������� ����� node1, ������ �� �������
    {
        Node* p = node1;
        node1 = node2;
        node2 = p;
    }
    Node* prev1 = Prev(node1);
    Node* prev2 = Prev(node2);
    Node* next1 = Next(node1);
    Node* next2 = Next(node2);
    if (next1 == node2) // ����� �������� �����
    {
        if (prev1 != NULL)
            prev1->ptr = node2;
        else
            head = node2;
        node2->ptr = node1;
        node1->ptr = next2;
        return;
    }
    if (prev1 != NULL)  // ����� ��������� �����
        prev1->ptr = node2;
    else
        head = node2;
    if (prev2 != NULL)
        prev2->ptr = node1;
    else
        head = node1;
    node2->ptr = next1;
    node1->ptr = next2;
}