#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* constructBST(int preorder[],int *preorderIDX,int key,int minn,int maxx,int n)
{
    if(*preorderIDX >= n)
    {
        return NULL;
    }
    Node* root = NULL;
    if(key > minn && key < maxx)
    {
        root = new Node(key);
        *preorderIDX = *preorderIDX + 1;
        if(*preorderIDX < n)
        {
            root->left = constructBST(preorder,preorderIDX,preorder[*preorderIDX],minn,key,n);
        }
        if(*preorderIDX < n)
        {
            root->right = constructBST(preorder,preorderIDX,preorder[*preorderIDX],key,maxx,n);
        }
    }
    return root;
}
void printpreorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
int main()
{
    int preorder[] = {10,2,1,13,11};
    int n = 5;
    int preorderIDX = 0;
    Node* root = constructBST(preorder,&preorderIDX,preorder[0],INT_MIN,INT8_MAX,n);
    printpreorder(root);
    return 0;
}