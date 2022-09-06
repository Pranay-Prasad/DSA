#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(a) for(int i = 0; i < a;i++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    For(n) cin>>a[i];
    int s = 0, ans = INT_MAX;
    For(k)
    {
        s += a[i];
    }
    cout<<s<<" ";
    ans = min(ans,s);
    for (int i = 1; i <= n-k+1; i++)
    {
        s -= a[i-1];
        s += a[i+k-1];
        ans = min(ans,s);
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}