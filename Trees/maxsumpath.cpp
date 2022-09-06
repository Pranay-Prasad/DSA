#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int maxp(Node* root,int &ans)
{
    if(root == NULL)
        return 0;
    int l = maxp(root->left,ans);
    int r = maxp(root->right,ans);
    int nodemax = max(max(l,r)+root->data,root->data);
    int single = max(nodemax,l+r+root->data);
    ans = max(ans,single);
    return nodemax;
}
int maxpath(Node* root)
{
    int ans = INT_MIN;
    maxp(root,ans);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    cout<<maxpath(root);
    return 0;
}