#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include "Node.h"
#include <string>
#include <sstream>

template<typename T>
class Tree
{
    Node<T>* root;
    Node<T>* insert_at_sub(T i, Node<T>*);
    Node<T>* delete_at_sub(const T& i, Node<T>* p);
    int countNodes(Node<T>* p);
    std::string print_sub(Node<T>* p, std::ostringstream& out);
    Node<T>* minValue(Node<T>*);
    Node<T>* maxValue(Node<T>*);
    Node<T>* get_last(Node<T>*);
    Node<T>* get_first(Node<T>*);
    int t_size = 0;

public:
    Tree()
    {
        root = nullptr;
    }

    ~Tree()
    {
        delete root;
    }

    void add(T i)
    {
        ++t_size;

        root = insert_at_sub(i, root);
    }
    std::string print()
    {
        std::ostringstream buffer{};
        print_sub(root, buffer);
        return buffer.str();
    };

    bool contain(T i)
    {
        return contain_sub(i, root);
    }
    bool contain_sub(T i, Node<T>* p);

    void destroy(T i)
    {
        if (contain(i))
            root = delete_at_sub(i, root);
        else
            return;
    }

    void showFirst();
    void showLast();

    int get_size()
    {
        return t_size;
    }

    int getNumberLeftNodes()
    {
        return countNodes(root->pLeft);
    }

    int getNumberRightNodes()
    {
        return countNodes(root->pRight);
    }
};

template<typename T>
int  Tree<T>::countNodes(Node<T>* p)
{
    static int nodes;

    if (!p)
        return 0;
    if (p->pLeft)
    {
        ++nodes;
        countNodes(p->pLeft);
    }
    if (p->pRight)
    {
        ++nodes;
        countNodes(p->pRight);
    }

    return nodes + 1;
}

template<typename T>
Node<T>* Tree<T>::insert_at_sub(T i, Node<T>* p)
{
    if (!p)
        return new Node<T>(i);
    else if (i <= p->val)
        p->pLeft = insert_at_sub(i, p->pLeft);
    else if (i > p->val)
        p->pRight = insert_at_sub(i, p->pRight);

    return p;
}

template<typename T>
std::string Tree<T>::print_sub(Node<T>* p, std::ostringstream& out)
{
    if (p != nullptr)
    {
        print_sub(p->pLeft, out);
        out << p->val << " ";
        print_sub(p->pRight, out);
    }
    return out.str();
}

template<typename T>
bool Tree<T>::contain_sub(T i, Node<T>* p)
{
    if (!p)
        return false;
    else if (i == p->val)
        return true;
    else if (i <= p->val)
        return contain_sub(i, p->pLeft);
    else
        return contain_sub(i, p->pRight);
}

template<typename T>

Node<T>* Tree<T>::minValue(Node<T>* p)
{
    Node<T>* current = p;

    while (current && current->pLeft)
        current = current->pLeft;

    return current;
}

template<typename T>
Node<T>* Tree<T>::maxValue(Node<T>* p)
{
    Node<T>* current = p;

    while (current && current->pRight)
        current = current->pRight;

    return current;
}

template<typename T>
void Tree<T>::showLast()
{
    Node<T>* last = maxValue(root);

    if (last)
        std::cout << last->val;
    else
        std::cout << "";
}

template<typename T>
void Tree<T>::showFirst()
{
    Node<T>* first = minValue(root);

    if (first)
        std::cout << first->val;
    else
        std::cout << "";
}


template<typename T>
Node<T>* Tree<T>::delete_at_sub(const T& i, Node<T>* p)
{
    if (!p)
        return p;

    // ���������� ���� ���� ��� ��������
    if (i < p->val)
        p->pLeft = delete_at_sub(i, p->pLeft);
    else if (i > p->val)
        p->pRight = delete_at_sub(i, p->pRight);
    else
    {
        // ���� ��� �������� ������

        // ���� ��� �������� ��� � ����� ��������
        if (!p->pLeft)
        {
            Node<T>* temp = p->pRight;
            delete p;
            return temp;
        }
        else if (!p->pRight)
        {
            Node<T>* temp = p->pLeft;
            delete p;
            return temp;
        }

        // ���� � ����� ���������
        Node<T>* temp = minValue(p->pRight);
        p->val = temp->val;
        p->pRight = delete_at_sub(temp->val, p->pRight);
    }

    return p;
}



#endif // TREE_H_INCLUDED