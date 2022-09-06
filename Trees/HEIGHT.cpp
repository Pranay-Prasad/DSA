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
int height(Node* root)
{
    if(!root)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l,r)+1;
}
int dia(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int currD = lh + rh +1;
    int ld = dia(root->left);
    int rd = dia(root->right);
    return max(currD,max(ld,rd));
}
int caldia(Node* root,int *h)
{
    if(root == NULL)
    {
        *h = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = caldia(root->left,&lh);
    int rd = caldia(root->right,&rh);
    int curr = lh + rh + 1;
    *h = max(lh,rh) + 1;
    return max(curr,max(ld,rd));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // root->right->right->right = new Node(8);
    int h = 0;
    cout<<caldia(root,&h)<<endl;
    return 0;
}