#include<bits/stdc++.h>
using namespace std;
/*
=======================================================================================================
1. We are using Priority queue for this 

 priority_queue<int>pq;

 -push()
 -pop()
 -top()
======================================================================================================
*/
int main()
{
    priority_queue<int>pq;
    pq.push(5);
    pq.push(10);
    pq.push(3);
    cout<<"Top of pq:"<<pq.top()<<endl;
    return 0;
}