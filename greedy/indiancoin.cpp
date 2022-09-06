#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(a) for(int i = 0; i < a ;i++)
#define LFor(i,a,b) for(int i = a; i <= b-1 ;i++)
#define vi vector<int>
#define mi map<int,int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    For(n) cin>>a[i];
    int x;
    cin>>x;
    sort(a.begin(),a.end(),greater<int>());
    int ans = 0;
    For(n)
    {
        ans += x/a[i];
        x -= x/a[i] * a[i];
    }
    cout<<ans<<endl;
    return 0;
}