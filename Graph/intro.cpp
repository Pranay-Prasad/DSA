#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int n;
vector<vector<int>> ans(n);
void print(vi adj[],int V)
{
    For(i,V)
    {
        For(j,adj[i].size())
        {
            ans[i].push_back(adj[i][j]);
        }
    }
}
void printl()
{
    For(i,n)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>n>>m;
    vi vec[n];
    For(i,m)
    {
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    print(vec,n);
    printl();
    return 0;
}