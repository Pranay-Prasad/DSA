#include<bits/stdc++.h>
using namespace std;
int getbit(int n,int pos)
{
    return ((n&(1<<pos)) != 0);
}
int setbit(int n,int pos)
{
    return ((n | (1<<pos)) != 0);
}
int clearbit(int n,int pos)
{
    int mask = ~(1<<pos);
    return ((n & mask) != 0);
}
int updatebit(int n,int pos,int value)
{
    int mask = ~(1<<pos);
    n = n&mask;
    return (n | (value<<pos));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<updatebit(5,2,0)<<endl;
    return 0;
}