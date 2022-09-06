#include <iostream>
#include <cmath>
using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     while (n>0)
//     {
//         int num = n%10;
//         n = n/10;
//         cout<<num;
//     }

//     return 0;
// }
//Armstrong number
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int orignal = n;
    while (n > 0)
    {
        int lastdig = n % 10;
        sum += pow(lastdig, 3);
        n = n / 10;
    }
    if (sum == orignal)
    {
        cout<<"Amstrong"<<endl;
    }
    else cout<<"NOt"<<endl;
    
}