#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    vector<vector<int>>a(k);
    for (int i = 0; i < k; i++)
    {
        int size;
        cin>>size;
        a[i] = vector<int>(size);
        for (int j = 0; j < size; j++)
        {
            cin>>a[i][j];
        }
        
    }
    vector<int> idx(k,0);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    for(int i = 0;i<k;i++)
    {
        pq.push({a[i][0],i});
    }
    vector<int>ans;
    while (!pq.empty())
    {
        pii x = pq.top();
        pq.pop();
        if(idx[x.second]+1 < a[x.second].size())
        {
            pq.push({a[x.second][idx[x.second]+1],x.second});
        }
        idx[x.second] += 1;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}