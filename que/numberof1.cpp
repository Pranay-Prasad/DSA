#include<bits/stdc++.h>
using namespace std;
int ones(int n)
{
    int num = n;
    int once = 0;
    while (num != 0)
    {
        int ret = (num & num-1);
        num = ret;
        once++;
    }
    return once;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<ones(19)<<endl;
    return 0;
}