#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
const int inf = 1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>>adj = { {0,5,inf,10},
                               {inf,0,3,inf},
                               {inf,inf,0,1},
                               {inf,inf,inf,0}
                              };
    int n = adj.size();
    vector<vector<int>>dist = adj;
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n;i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
            
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if(dist[k][i] == inf)
                cout<<"inf"<<" ";
            else
                cout<<dist[k][i]<<" ";
            
        }
        cout<<endl;
    }
    
    return 0;
}