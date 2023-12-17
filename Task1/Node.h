#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template<typename T>
class Node
{
public:
    Node<T>* pLeft;
    Node<T>* pRight;
    T val;

    Node<T>(T val)
    {
        this->val = val;
        pLeft = pRight = nullptr;
    }

};


#endif // NODE_H_INCLUDED