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
        data =  val;
        left = NULL;
        right = NULL;
    }
};
int countN(Node* node)
{
    if(node == NULL)
    {
        return 0;
    }
    int count = 1;
    count +=(countN(node->left) + countN(node->right));
    return count;
}
int sumofN(Node* root)
{
    if(root == NULL)
        return 0;
    int sum = root->data;
    int l = sumofN(root->left);
    int r = sumofN(root->right);
    return sum+l+r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    cout<<sumofN(root);
    return 0;
}