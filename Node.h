#pragma once

#include <memory>

using namespace std;

template <class C> class Node
{
public:
    Node(C item);
    ~Node();
    C GetVal();
    void SetVal(C);

    shared_ptr<Node> lt;
    shared_ptr<Node> rt;

private:
    C val;
};

#include "Node.cpp"