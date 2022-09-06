	#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
const int N = 1e5 +7;
vi adj[N];
bool vis[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    For(i,N)
        vis[i] = 0;
    int n,m;
    cin>>n>>m;
    For(i,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>ans;
    queue<int>q;
    q.push(0);
    vis[0] = true;
    int i = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<"i: "<<i<<" "<<node<<" ";
        ans.push_back(node);
        vi :: iterator it;
        for(it = adj[node].begin();it != adj[node].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it] = true;
                q.push(*it);
            }
        }
        i++;
    }
    cout<<endl;
    for(int i = 0; i < ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}
