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
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data  = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
bool s1(Node* r1,Node* r2){
    return r1==r2;
}
Node* deleteLeaf(Node* root){
    // cout<<"YES"<<endl;
    if(!root)
        return NULL;
    if(!root->left && !root->right){
        free(root);
        return NULL;
    }
    root->left = deleteLeaf(root->left); 
    root->right = deleteLeaf(root->right); 
    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct Node* root = new Node(4);
    root->left = new Node(1);
    root->left->left = new Node(0);
    root->left->right = new Node(2);
    root->left->right->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    inorder(root);
    root = deleteLeaf(root);
    cout<<endl;
    inorder(root);
    return 0;
}