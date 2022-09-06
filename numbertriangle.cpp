#include<iostream>
using namespace std;
int main()
{
    int n,num = 1;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (int j = 0; j < i; j++)
        {
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
        num = 1;
    }
    
    return 0;
}