#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{
    vector<bool>prime(n+1,true);
    for (int i = 2; i <= n; i++)
    {
        if(prime[i] == true)
        {
            cout<<i<<" ";
            for (int j = i*i; j <= n; j+=i)
            {
                prime[j] = false;
            }
            
        }
    }
    // for (int i = 2; i < n; i++)
    // {
    //     if(prime[i] == true)
    //     {
    //         cout<<i<<" ";
    //     }
    // }
    
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    solve(n);
    return 0;
}