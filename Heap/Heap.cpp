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


/*
=======================================================================================================
4. Heap sort 
======================================================================================================
*/

//heapify for heap sort 

void heapify(int i , vector<int>&v, int n)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int maxIndex = i;
    if(left<n && v[left]>v[maxIndex])
    {
        maxIndex = left;
    }

    if(right<n && v[right]>v[maxIndex])
    {
        maxIndex = right;
    }

    if(maxIndex!=i)
    {
        swap(v[i],v[maxIndex]);
        heapify(maxIndex,v,n);
    }
}

void heapSort(vector<int>&v)
{
    int n = v.size();

    //step 1 : build max heap
    for(int i = n/2-1; i>=0; i--)
    {
        heapify(i,v,n);
    }

    //step 2: placing to correct positions  
    for(int i = n-1; i>=0 ; i--)
    {
        swap(v[0], v[i]);
        heapify(0,v,i);
    }
}


int main()
{
    // 3.PQ for pairs: 
    // priority_queue<pair<string,int>,vector<pair<string,int>>,comparePairs> pq;



    //4. Heap sort 
    vector<int>v = {10,20,5,6,1,8,9};
    heapSort(v);
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}