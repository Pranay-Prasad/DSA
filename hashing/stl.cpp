#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int>mp;
    unordered_map<int,int>ump;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i <n;i++)
    {
        cin>>arr[i];
    }
    for(int i = 0;i < n;i++)
    {
        mp[arr[i]]++;
    }
    map<int,int>::iterator itr;
    for(itr = mp.begin();itr != mp.end(); itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    return 0;
}