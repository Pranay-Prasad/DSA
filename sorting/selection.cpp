#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
//time complexity = O(n^2);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 6;
    int arr[n] = {2,7,4,1,5,3};
    // Not to use extra array to save memory
    for(int i = 0; i<n-1;i++)
    {
        int minn = i;
        for(int j = i; j <n-1;j++)
        {
            if(arr[j] < arr[minn])
                minn = j;
        }
        swap(arr[minn],arr[i]);
    }
    for(int i = 0; i < n;i++)
        cout<<arr[i]<<" ";
    return 0;
}