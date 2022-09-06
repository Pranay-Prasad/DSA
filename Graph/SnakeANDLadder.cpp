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
    int ladders,snakes;
    cout<<"1: "<<endl;
    cin>>ladders;
    mi lad;
    mi snk;
    For(i,ladders)
    {
        cout<<"laders: "<<endl; 
        int u,v;
        cin>>u>>v;
        lad[u] = v;
    }
    cout<<"s: "<<endl;
    cin>>snakes;
    For(i,snakes)
    {
        cout<<"Snake: "<<endl;
        int u,v;
        cin>>u>>v;
        snk[u] = v;
    }
    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int>vis(101,0);
    vis[1] = true;
    while (!q.empty() and !found)
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            for(int die = 1; die <= 6; die++)
            {
                if(t + die == 100)
                    found = true;
                if(t + die <= 100 and lad[t+die] and !vis[lad[t+die]])
                {
                    vis[lad[t+ die]] = true;
                    if(lad[t+die] == 100)
                        found = true;
                    q.push(lad[t+die]);
                }
                else if(t + die <= 100 and snk[t + die] and !vis[snk[t+die]])
                {
                    vis[snk[t+die]] = true;
                    if(snk[t+die] == 100)
                        found = true;
                    q.push(snk[t+die]);
                }
                else if(t + die <= 100 and !vis[t+die] and !snk[t+die] and !lad[t+die])
                {
                    vis[t+die] = true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }
    if(found)
        cout<<moves<<endl;
    else
        cout<<-1<<endl;
    return 0;
}