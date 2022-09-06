#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
void calFib(int n)
{
    ll f[n+2];
    ll i;
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    for(int j = 1; j <= n; j++)
        cout<<f[j]<<" ";
}
//using DP 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    calFib(n);
    return 0;
}