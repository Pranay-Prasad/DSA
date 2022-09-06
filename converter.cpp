#include <bits/stdc++.h>
using namespace std;
// int binarytodecimal(int n)
// {
//     int ans = 0;
//     int x = 1;
//     while (n > 0)
//     {
//         int y = n % 10;
//         ans += x * y;
//         x *= 2;
//         n = n / 10;
//     }
//     return ans;
// }
// int octaltodecimal(int n)
// {
//     int ans = 0;
//     int x = 1;
//     while (n > 0)
//     {
//         int y = n % 10;
//         ans += x * y;
//         x *= 8;
//         n = n / 10;
//     }
//     return ans;
// }
// int hexatodecimal(string n)
// {
//     int ans = 0;
//     int x = 1;
//     int s = n.size();
//     for(int i = s-1; i >= 0; i--)
//     {
//         if (n[i] >= '0' && n[i] <= '9')
//         {
//             ans += x*(n[i] - '0');
//         }
//         else if(n[i] >= 'A' && n[i] <= 'F')
//         {
//             ans += x*(n[i] - 'A' + 10);
//         }
//         x *= 16;
//     }
//     return ans;
// }
int decimaltobinary(int n)
{
    int x = 1;
    int ans = 0;
    while (x <= n)
    {
        x *= 2;
    }
    x /= 2;
    while (x > 0)
    {
        int lastdig = n / x;
        n -= lastdig * x;
        x /= 2;
        ans = ans * 10 + lastdig;
    }
    return ans;
}
int decimaltooctal(int n)
{
    int x = 1;
    int ans = 0;
    while (x <= n)
    {
        x *= 8;
    }
    x /= 8;
    while (x > 0)
    {
        int lastdig = n / x;
        n -= lastdig * x;
        x /= 8;
        ans = ans * 10 + lastdig;
    }
    return ans;
}
string decimaltohexadecimal(int n)
{
    int x = 1;
    string ans = "";
    while (x <= n)
    {
        x *= 16;
    }
    x /= 16;
    while(x>0)
    {
        int lastdigt = n/x;
        n -= lastdigt*x;
        x /= 16;
        if(lastdigt <= 9)
        {
            ans = ans + to_string(lastdigt);
        }
        else{
            char c ='A' + lastdigt -10;
            ans.push_back(c);
        }
    }
    return ans;
}
// int addtobinary(int a,int b)
// {
//     int ans =0;
//     int previouscarry = 0;
//     while (a >0 && b> 0)
//     {
//         if(a%2 == 0 && b%2 == 0)
//         {
//             ans = ans*10 + previouscarry;
//             previouscarry = 0;
//         }
//         else if ((a%2 == 0 && b%2 == 1 )|| (a%2 == 1&& b%2 == 0))
//         {
//             if (previouscarry == 1)
//             {
//                 ans = ans*10 + 0;
//                 previouscarry = 1;
//             }
//             else
//             {
//                 ans = ans*10 + 1;
//                 previouscarry = 0;
//             }
            
//         }
//         else{
//             ans = ans*10 + previouscarry ;
//             previouscarry = 1;
//         }
//         a /= 10;
//         b /= 10;
//     }
//     while (a > 0)
//     {
//         if(previouscarry == 1)
//         {
//             ans = ans*10 + 0;
//         }
//         else{
//             ans = ans*10 + 1;
//             previouscarry = 0;
//         }
//     }
//     while (a>0)
//     {
//         if()
//     }
    
    
// }
int main()
{
    int a = -18;
    cout << decimaltobinary(a) << endl;
}