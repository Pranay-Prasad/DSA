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
    for(int i = st;i <= en ;i++)
    {
        if(inor[i] == curr)
        {
            // cout<<"i: "<<i<<endl;
            return i;
        }
    }
    return -1;
}
Node* build(int pre[], int inor[],int st,int en)
{
    static int idx = 0;
    if(st > en)
    {
        return NULL;
    }
    int curr = pre[idx];
    idx++;
    Node* node = new Node(curr);
    if(st == en)
    {
        return node;
    }
    // cout<<"yes"<<endl;
    int pos = searcht(inor,st,en,curr);
    node->left = build(pre,inor,st,pos-1);
    node->right = build(pre,inor,pos+1,en);
    return node;
}
void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int pre[]= {1,2,4,5,3,6};
    int inor[] = {4,2,5,1,3,6};
    Node* root = build(pre,inor,0,5);
    inorder(root);
    return 0;
}