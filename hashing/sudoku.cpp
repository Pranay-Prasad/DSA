#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(a) for(int i = 0; i < a ;i++)
#define LFor(i,a,b) for(int i = a; i < b ;i++)
#define vi vector<int>
#define mi map<int,int>
void helper(int r,int c,vector<vector<char>> &a,map<pair<int,int>,mi> &mp,vector<mi> row,vector<mi> col)
{
    
}
void solvesudoku(vector<vector<char>> &a)
{
    map<pair<int,int>,mi>mp;
    vector<mi>row(9);
    vector<mi>col(9);
    For(9)
    {
        LFor(j,0,9)
        {
            if(a[i][j] != '.')
            {
                mp[{i/3,j/3}][a[i][j]- ' 0'] = 1;
                row[i][a[i][j] - ' 0'] = 1;
                col[j][a[i][j] - ' 0'] = 1;
            }
        }
    }
    helper(0,0,a,mp,row,col);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<char>> suduku = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','.','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    solvesudoku(suduku);
    return 0;
}