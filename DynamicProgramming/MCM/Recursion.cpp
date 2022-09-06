#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int MCM(int arr[],int i,int j)
{
    if(i >= j)
        return 0;
    ll ans = LONG_MAX;
    for(int k = i;k <= j-1;k++)
    {
        ll tempans = (MCM(arr,i,k) + MCM(arr,k+1,j) + (arr[i-1] * arr[k] * arr[j]));
        ans = min(ans,tempans);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[5] = {40,20,30,10,30};
    int i = 1;
    int j = 4;
    cout<<MCM(arr,i,j)<<endl;
    return 0;
}