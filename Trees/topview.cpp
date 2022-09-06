#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
struct node
{
    int data;
    int hd;
    node* left = NULL;
    node* right = NULL;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void top(node* root)
{
    // if(root == NULL)
    // {
    //     return;
    // }
    // queue<node*>q;
    // map<int,int>m;
    // int idx = 0;
    // q.push(root);
    int hd = 0;
    root->hd = hd;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    return 0;
}