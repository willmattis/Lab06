#include <memory>

using namespace std;

template <class C> Node<C>::Node(C item)
{
	val = item;
	lt = nullptr; //left branch
	rt = nullptr; //right branch
}

template <class C> Node<C>::~Node()
{
    lt = nullptr;
    rt = nullptr;
}

template <class C> C Node<C>::GetVal()
{
    return val;
}

template <class C> void Node<C>::SetVal(C item){
    val = item;
}
