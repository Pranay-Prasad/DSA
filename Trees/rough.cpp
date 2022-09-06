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
void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* solve(Node* root){
    if(!root){
        return NULL;
    }
    if(!root->left && !root->right){
        return NULL;
    }
    root->left = solve(root->left);
    root->right = solve(root->right);
    if(!root->left && !root->right){
        return NULL;
    }
    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    // Node* node = solve(root);
    // if(!node){
    //     cout<<"NO root"<<endl;
    // }
    // inorder(node);
    cout<<((1+5)/1)<<endl;
    return 0;
}