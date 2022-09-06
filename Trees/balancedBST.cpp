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
Node* BBST(int arr[],int start,int end)
{
    if(start > end)
        return NULL;
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);
    root->left = BBST(arr,start,mid-1);
    root->right = BBST(arr,mid+1,end);
    return root;
}
void inorder(Node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {10,20,30,40,50};
    Node* root = BBST(arr,0,4);
    inorder(root);
    return 0;
}