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
        data =val;
        left = NULL;
        right = NULL;
    }
};
int height(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh)+1;
}
bool balanced(Node* root)
{
    if (root == NULL)
    {
        return true;
    }
    
    if (balanced(root->left) == false)
    {
        return false;
    }
    if (balanced(root->right) == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh-rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isbalance(Node* root,int* height)
{
    if (root == NULL)
    {
        return true;
    }
    
    int lh = 0, rh = 0;
    if (isbalance(root->left,&lh) == false)
    {
        return false;
    }
    if (isbalance(root->right,&rh) == false)
    {
        return false;
    }
    *height = max(lh,rh)+1;
    if (abs(lh-rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void rightview(Node* root)
{
    int n;
    if (root== NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        n = q.size();
        for(int i = 0; i < n; i++)
        {
            Node* curr = q.front();
            q.pop();
            if (i == n-1)
            {
                cout<<curr->data<<" ";
            }
            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
            if(curr->left != NULL)
            {
                q.push(curr->left);
            }
        }
    }
    
}
void leftview(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);

}
Node* LCA(Node* root,int n1,int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node* left = LCA(root->left,n1,n2);
    Node* right = LCA(root->right,n1,n2);
    if (right != NULL && left != NULL)
    {
        return root;
    }
    if (right == NULL && left == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(root->left,n1,n2);
    }
    if (right != NULL)
    {
        return LCA(root->right,n1,n2);
    }

}
int finddistance(Node* root,int k,int dis)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dis;
    }
    int left = finddistance(root->left,k,dis+1);
    if (left != -1)
    {
        return left;
    }
    return finddistance(root->right,k,dis+1);
}
int dist(Node* root,int n1,int n2)
{
    Node* lca = LCA(root,n1,n2);
    int d1 = finddistance(root,n1,0);
    int d2 = finddistance(root,n2,0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left  = new Node(4);
    root->left->right  = new Node(5);
    root->right->left  = new Node(6);
    root->right-> right = new Node(7);
    // root->right->right->left = new Node(12);
    // int h = 0;
    // if (isbalance(root,&h))
    // {
    //     cout<<"YES"<<endl;
    // }
    // else
    //     cout<<"NO"<<endl;
    // rightview(root);
    cout<<dist(root,4,7);
    return 0;
}