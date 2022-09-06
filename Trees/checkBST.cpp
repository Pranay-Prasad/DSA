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
bool CheckBST(Node* root,Node* minn = NULL,Node* maxx = NULL)
{
    if(root == NULL)
    {
        return true;
    }
    if(minn != NULL && root->data <= minn->data)
    {
        return false;
    }
    if(maxx != NULL && root->data >= maxx->data)
    {
        return false;
    }
    bool leftvalid = CheckBST(root->left,minn,root);
    bool rightvalid = CheckBST(root->right,root,maxx);
    return leftvalid and rightvalid;

}
int main()
{
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(8);
    if(CheckBST(root))
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}