#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define PFor(i,a,b) for(int i = a; i < b ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<vector<int>>v;
    For(i,n)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),[&](vi &a,vi &b){return a[1] < b[1];});
    int take = 1;
    int end = v[0][1];
    PFor(i,1,n)
    {
        if(v[i][0] >= end)
        {
            take++;
            end = v[i][1];
        }
    }
    cout<<take<<endl;
    return 0;
}