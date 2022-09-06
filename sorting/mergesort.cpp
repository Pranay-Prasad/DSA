#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
void midsort()
void mergesort(vi &vec,int n)
{

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi vec;
    for(int i = 0;i<n;i++)
        cin>>vec[i];
    mergesort(vec,n);
    for(int i = 0; i <n;i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}