#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
const int N = 1e5 + 5;
vi parent(N);
vi sz(N);
void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int key)
{
    if(key == parent[key])
    {
        return key;
    }
    return parent[key] = find_set(parent[key]);
}
void union_set(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if( a != b)
    {
        if(sz[a] < sz[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < N;i++)
    {
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>>ed;
    For(i,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ed.push_back({w,u,v});
    }
    sort(ed.begin(),ed.end());
    int cost = 0;
    for(auto x : ed)
    {
        int w = x[0];
        int u = x[1];
        int v = x[2];
        int i = find_set(u);
        int j = find_set(v);
        if(i == j)
        {
            continue;
        }
        else
        {
            cout<<u<<" "<<v<<endl;
            cost += w;
            union_set(u,v);
        }
    }
    cout<<cost<<endl;
    return 0;
}