#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<int,vector<int>>pq_max;
priority_queue<int,vector<int>,greater<int>>pq_min;
void insert(int x)
{
    if(pq_min.size() == pq_max.size())
    {
        if(pq_max.size() == 0)
        {
            pq_max.push(x);
            return;
        }
        if(x < pq_max.top())
        {
            pq_max.push(x);
        }
        else
        {
            pq_min.push(x);
        }
    }
    else
    {
        if(pq_max.size()>pq_min.size())
        {
            if(x >= pq_max.top())
            {
                pq_min.push(x);
            }
            else
            {
                int temp = pq_max.top();
                pq_max.pop();
                pq_min.push(temp);
                pq_max.push(x);
            }
        }
        else
        {
            if(x <= pq_min.top())
            {
                pq_max.push(x);
            }
            else
            {
                int temp = pq_min.top();
                pq_min.pop();
                pq_max.push(temp);
                pq_min.push(x);
            }
        }
    }
}
double findmedian()
{
    if(pq_min.size() == pq_max.size())
    {
        return(pq_min.top() + pq_max.top())/2.0;
    }
    else if(pq_min.size() < pq_max.size())
    {
        return pq_max.top();
    }
    else
    {
        return pq_min.top();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    insert(10);
    cout<<findmedian()<<endl;
    insert(15);
    cout<<findmedian()<<endl;
    insert(21);
    cout<<findmedian()<<endl;
    insert(30);
    cout<<findmedian()<<endl;
    insert(18);
    cout<<findmedian()<<endl;
    insert(19);
    cout<<findmedian()<<endl;
    return 0;
}