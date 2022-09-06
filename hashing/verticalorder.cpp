#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
void vertical(Node* root,int distance,map<int,vector<int>> &mp)
{
    if(root == NULL)
    {
        return;
    }
    mp[distance].push_back(root->data);
    vertical(root->left,distance-1,mp);
    vertical(root->right,distance+1,mp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);
    map<int,vector<int>>mp;
    int distance = 0;
    vertical(root,distance,mp);
    map<int,vector<int>>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout<<(it->second)[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}