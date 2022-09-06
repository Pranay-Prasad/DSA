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
    int n,k;
    cin>>n>>k;
    vi a(n);
    For(n) cin>>a[i];
    mi freq;
    For(n)
    {
        int present = freq.size();
        if(freq[a[i]] == 0 && present == k)
        {
            break;
        }
        freq[a[i]]++;
    }
    vector<pair<int,int>> ans;
    map<int,int>::iterator it;
    for(it = freq.begin(); it != freq.end();++it)
    {
        if(it->second != 0)
        {
            ans.push_back({it->second,it->first});
        }
    }
    sort(ans.begin(),ans.end(),greater<pair<int,int>>());
    vector<pair<int,int>>::iterator itr;
    for(itr = ans.begin(); itr!= ans.end() ; itr++)
    {
        cout<<itr->second<<" "<<itr->first<<endl;
    }
    return 0;
}