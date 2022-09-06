#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int,vector<int>>pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);
    pq.pop();
    // cout<<pq.top()<<endl;
    priority_queue<int,vector<int>,greater<int>>pqm;
    pqm.push(2);
    pqm.push(1);
    pqm.push(2);
    cout<<pqm.top()<<endl;
    return 0;
}