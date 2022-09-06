#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    vector<int>indeg(n,0);
    For(i,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    queue<int>q;
    for(int i = 0; i < n; i++)
    {
        if(indeg[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        count++;
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(auto it : adj[x])
        {
            indeg[it]--;
            if(indeg[it] == 0)
                q.push(it);
        }
    }
    
    return 0;
}