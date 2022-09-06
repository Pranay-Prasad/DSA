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
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* LCA(Node* root,int n1,int n2)
{
    if(root == NULL)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    Node* left = LCA(root->left,n1,n2);
    Node* right = LCA(root->right,n1,n2);
    if(left != NULL && right != NULL)
        return root;
    if(left == NULL && right == NULL)
        return NULL;
    if(left != NULL)
        return LCA(root->left,n1,n2);
    return LCA(root->right,n1,n2);
}
int finddis(Node* root,int k,int n)
{
    if(root== NULL)
        return -1;
    if(root->data == k)
        return n;
    int left = finddis(root->left,k,n+1);
    if(left != -1)
        return left;
    return finddis(root->right,k,n+1);
}
int dist(Node* root,int n1,int n2)
{
    Node* lca = LCA(root,n1,n2);
    cout<<"lca: "<<lca->data<<endl;
    int d1 = finddis(lca,n1,0);
    int d2 = finddis(lca,n2,0);
    return d1+d2;
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
    root->left->right->right = new Node(6);
    Node* dis = LCA(root,5,6);
    cout<<dis->data<<endl;
    return 0;
}