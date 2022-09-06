#include<iostream>
using namespace std;
void facto(int n,int r)
{
    int fact1 = 1,fact2 = 1,fact3 = 1;
    for (int i = 1; i <= n; i++)
    {
        fact1 *= i;
    }
    for (int i = 1; i <= r; i++)
    {
        fact2 *= i;
    }
    for (int i = 1; i <= n-r; i++)
    {
        fact3 *= i;
    }
    double ncr = fact1/(fact3*fact2);
    cout<<ncr<<endl;
}
int main()
{
    int n,r;
    cin>>n>>r;
    facto(n,r);
    return 0;
}