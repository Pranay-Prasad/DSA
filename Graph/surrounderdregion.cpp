#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<char>>A(n,vector<char>(m));
    For(i,n)
    {
        For(j,m)
        {
            cin>>A[i][j];
        }
    }
    For(i,n)
    {
        For(j,m)
        {
            if(i == 0 || i == n-1 || j == 0 || j == m-1)
            {
                if(A[i][j] == 'O')
                    A[i][j] = '*';
            }
        }
    }
    For(i,n)
    {
        For(j,m)
        {
            if(A[i][j] == 'O')
                A[i][j] = 'X';
        }
    }
    For(i,n)
    {
        For(j,m)
        {
            if(A[i][j] == '*')
                A[i][j] = 'O';
        }
    }
    cout<<endl;
    For(i,n)
    {
        For(j,m)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}