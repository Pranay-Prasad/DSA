#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(a) for(int i = 0;i < a ;i++)
#define parFor(i,a,b) for(int i = a; < b ;i++);
#define vi vector<int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    For(n)
    {
        cin>>a[i];
    }
    map<int,int>cnt;
    int prefsem = 0;
    For(n)
    {
        prefsem += a[i];
        cnt[prefsem]++;
    }
    int ans = 0;
    map<int,int>::iterator it;
    for(it = cnt.begin(); it != cnt.end();it++)
    {
        int c = it->second;
        ans += (c*(c-1))/2;
        if(it->first == 0)
    }
    return 0;
}