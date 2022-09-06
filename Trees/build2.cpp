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
int searcht(int inor[],int st,int en,int curr)
{
    for(int i = st; i >= en;i--)
    {
        if(inor[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
Node* build(int post[],int inor[],int st,int en)
{
    static int idx = 6;
    if(st < en)
    {
        return NULL;
    }
    int curr = inor[idx];
    idx--;
    Node* node = new Node(curr);
    if(st == en)
        return node;
    int pos = searcht(inor,st,en,curr);
    node->right = build(post,inor,st,pos+1);
    node->left = build(post,inor,pos-1,en);
    return node;
}
void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int post[] = {4,5,2,6,7,3,1};
    int inor[] = {4,2,5,1,6,3,7};
    Node* root = build(post,inor,6,0);
    inorder(root);
    return 0;
}