#include<bits/stdc++.h>
using namespace std;
/*
=======================================================================================================
1. creating Heap, push and POP()
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

    void heapify(int i ){ //i = prent index
        if(i>=v.size())
        {
            return;
        }

        int l = 2*i+1;
        int r = 2*i+2;
        int maxIndex = i;
        if(l<v.size() && v[l]>v[maxIndex])
        {
            maxIndex = l;
        }
        if(r<v.size() && v[r]>v[maxIndex])
        {
            maxIndex = r;
        }

        swap(v[i],v[maxIndex]);
        if(maxIndex!=i)
        {
            heapify(maxIndex);
        }
    } 

    void pop()
    {
        v[0] = v[v.size()-1];
        v.pop_back();
        heapify(0);
    }

    int top()
    {
        return v[0];
    }

    bool empty()
    {
        return v.size()==0;
    }

};


/*
=======================================================================================================
2. PQ for objects
======================================================================================================
*/

class Students{
    public:
    string name;
    int marks;
    Students(string name, int marks)
    {
        this->name = name;
        this->marks = marks;
    }

    //operator overloading
    bool operator < (const Students &s) const
    {
        return this->marks<s.marks;
    }

};


/*
=======================================================================================================
3. PQ for pairs
======================================================================================================
*/

struct comparePairs{
    bool operator () (pair<string,int>&p1, pair<string,int>&p2)
    {
        return p1.second < p2.second;
    }
};


int main()
{
    priority_queue<pair<string,int>,vector<pair<string,int>>,comparePairs> pq;
    int n;
    cin>>n; 
    for(int i=0;i<n;i++)
    {
        string name;
        int marks;
        cin>>name>>marks;
        pq.push(make_pair(name,marks));
    }

    while(!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}