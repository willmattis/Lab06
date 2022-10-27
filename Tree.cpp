#include <string>
#include <vector>
#include <memory>

using namespace std;

template <class C> 
Tree<C>::Tree()
{
    root = nullptr;
}

template <class C> 
Tree<C>::~Tree()
{
    Clear();
    root = nullptr;
}
/*
template <class C> shared_ptr<Node<C>> Tree<C>::Find(C item)
{
    
}
*/

template <class C> shared_ptr<Node<C>> Tree<C>::Insert(C item)
{
    return Insert(root, item);
}

template <class C> shared_ptr<Node<C>> Tree<C>::Insert(shared_ptr<Node<C>> n, C item)
{
    if (n == nullptr){
        shared_ptr<Node<C>> newN(new Node<C>(item));
        if (root == nullptr){
            root = newN;
        }
        return newN;
    }

    if (item < n->GetVal())
    {
        n->lt = Insert(n->lt, item);
    }
    else if(item > n->GetVal()) 
    {
        n->rt = Insert(n->rt, item);
    }

    return n;
}
/*
template <class C> vector<C> Tree<C>::GetAllAsc(shared_ptr<Node<C>> n)
{
    vector<C> vals;

    if (n == nullptr) return vals;

    if (n->lt != nullptr)
    {
        vector<C> ltVals = GetAllAsc(n->lt); //Left values
        vals.Insert(vals.end(), ltVals.begin(), ltVals.end());
    }

    vals.push_back(n->GetValue());

    if (n->rt != nullptr)
    {
        vector<C> rtVals = GetAllAsc(n->rt); //Right values
        vals.Insert(vals.end(), rtVals.begin(), rtVals.end());
    }

    return vals;
}
*/











template <class C> shared_ptr<Node<C>> Tree<C>::Find(C item)
{
    return Find(root, item);
}

template <class C> shared_ptr<Node<C>> Tree<C>::Find(shared_ptr<Node<C>> n, C item)
{
    if (n == nullptr) {return nullptr;}
    if (n->GetVal() == item) {return n;}

    if (n->lt != nullptr)
    {
        shared_ptr<Node<C>> match = Find(n->lt, item);
        if (match != nullptr) {return match;}
    }
    if (n->rt != nullptr)
    {
        shared_ptr<Node<C>> match = Find(n->rt, item);
        if (match != nullptr) {return match;}
    }

    return nullptr;

}

/*
template <class C> shared_ptr<Node<C>> Tree<C>::Insert(C item)
{
    return Insert(root, item);
}

template <class C> shared_ptr<Node<C>> Tree<C>::Insert(shared_ptr<Node<C>> n, C item)
{
    if (n == nullptr){
        shared_ptr<Node<C>> newN(new Node<C>(item));
        if (root == nullptr){
            root = newN;
        }
        return newN;
    }

    if (item < n->GetVal())
    {
        n->lt = Insert(n->lt, item);
    }
    else if(item > n->GetVal()) 
    {
        n->rt = Insert(n->rt, item);
    }

    return n;
}
*/





template <class C> vector<C> Tree<C>::GetAllAsc()
{
    return GetAllAsc(root);
}

template <class C> vector<C> Tree<C>::GetAllAsc(shared_ptr<Node<C>> n)
{
    vector<C> vals;

    if (n == nullptr) return vals;

    if (n->lt != nullptr)
    {
        vector<C> ltVals = GetAllAsc(n->lt); //Left values
        vals.insert(vals.end(), ltVals.begin(), ltVals.end());
    }

    vals.push_back(n->GetVal());

    if (n->rt != nullptr)
    {
        vector<C> rtVals = GetAllAsc(n->rt); //Right values
        vals.insert(vals.end(), rtVals.begin(), rtVals.end());
    }

    return vals;
}

template <class C> int Tree<C>::Size() const
{
    return Size(root);
}

template <class C> int Tree<C>::Size(shared_ptr<Node<C>> n) const
{
    if (n == nullptr) return 0;

    int tSize = 0; //Total size

    shared_ptr<Node<C>> lt = n->lt;
    shared_ptr<Node<C>> rt = n->rt;

    if (lt != nullptr) tSize += Size(lt);
    if (rt != nullptr) tSize += Size(rt);

    tSize ++;

    return tSize;
}

template <class C> void Tree<C>::Clear()
{
    root = nullptr;
}

