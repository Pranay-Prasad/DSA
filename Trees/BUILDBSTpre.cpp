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
Node* consBST(int pre[],int *idx,int key,int minn,int maxx,int n)
{
    if(*idx >= n)
    {
        return NULL;
    }
    Node* root = NULL;
    if(key > minn && key < maxx)
    {
        root = new Node(key);
        (*idx)++;
        if(*idx < n)
        {
            root->left = consBST(pre,idx,pre[*idx],minn,key,n);
        }
        if(*idx < n)
        {
            root->right = consBST(pre,idx,pre[*idx],key,maxx,n);
        }
    }
    return root;
}
void preorder(Node* root)
{
    if(root == NULL)
        return;
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int pre[] = {4,2};
    int n = 2;
    int idx = 0;
    Node* root = consBST(pre,&idx,pre[0],INT_MIN,INT_MAX,n);
    preorder(root);
    return 0;
}