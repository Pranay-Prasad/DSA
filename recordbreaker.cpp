#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int i = 0; i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        if(n == 1)
        {
            cout<<"1"<<endl;
            return 0;
        }
        int maxx = -1;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maxx && arr[i] > arr[i+1])
            {
                count++;
            }
            maxx = max(maxx,arr[i]);
            
        }
        cout<<"Case #"<<i+1<<": "<<count<<endl;
    }
    
    return 0;
}