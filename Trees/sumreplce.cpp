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
void sumr(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    sumr(root->right);
    if(root->left != NULL)
    {
        root->data += root->left->data;
    }
    if(root->right != NULL)
    {
        root->data += root->right->data;
    }
    sumr(root->left);
}
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
    preorder(root);
    sumr(root);
    cout<<endl;
    preorder(root);
    return 0;
}