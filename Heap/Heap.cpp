#include<bits/stdc++.h>
using namespace std;
/*
=======================================================================================================
1. creating Heap
======================================================================================================
*/
class Heap{
    vector<int>v;
    public:
    void push(int val)
    {
        v.push_back(val);
        int x = v.size()-1;
        int parent = (x-1)/2;
        while(parent>=0 && v[parent]<v[x])
        {
            swap(v[parent],v[x]);
            x = parent;
            parent = (x-1)/2;
        }
    }

    void pop()
    {

    }

    int top()
    {
        return v[0];
    }

    int empty()
    {
        return v.size()==0;
    }

};

int main()
{
    Heap heap;
    heap.push(5);
    heap.push(15);
    heap.push(25);
    cout<<"Top of heap:"<<heap.top()<<endl;
    return 0;
}