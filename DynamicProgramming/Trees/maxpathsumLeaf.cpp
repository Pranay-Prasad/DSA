#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
struct  Node
{
    int data;
    Node* left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int solve(Node* root,int &ans)
{
    if(root == NULL)
        return 0;
    int l = solve(root->left,ans);
    int r = solve(root->right,ans);
    if(root->left && root->right)
    {
        ans = max(ans,l+r+root->data);
        return max(l,r)+root->data;
    }
    return (!root->left)?r+root->data : l+root->data;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = new Node(20);
    root->left = new Node(9);
    root->right = new Node(-1);
    root->left->left = new Node(-2);
    root->left->right = new Node(10);
    root->left->right->left = new Node(-40);
    root->left->right->right = new Node(6);
    int ans = INT_MIN;
    cout<<solve(root,ans)<<endl;

    return 0;
}