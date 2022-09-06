#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int cat(int n)
{
    if(n <= 1)
        return 1;
    int res = 0;
    for(int i = 0; i <= n-1 ;i++)
    {
        res += cat(i) * cat(n-i-1);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    For(i,10)
    {
         cout<<cat(i)<<" ";
    }
    return 0;
}