#include<iostream>
using namespace std;
void fibonace(int num)
{
    int t1 = 0;
    int t2 = 1;
    int sum;
    for (int i = 0; i < num; i++)
    {
        cout<<t1<<endl;
        sum = t1+t2;
        t1 = t2;
        t2 =  sum;
    }
    return;
}
int main()
{
    int  n;
    cin>>n;
    fibonace(n);
    return 0;
}