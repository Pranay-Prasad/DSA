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
vector<Node*> construct(int start,int end)
{
    vector<Node*>tree;
    if(start > end)
    {
        tree.push_back(NULL);
        return tree;
    }
    for(int i = start; i <= end;i++)
    {
        vector<Node*>leftsubtree = construct(start,i-1);
        vector<Node*>rightsubtree = construct(i+1,end);
        for(int j = 0; j < leftsubtree.size(); j++)
        {
            Node* left = leftsubtree[j];
            for(int k = 0; k < rightsubtree.size();k++)
            {
                Node* right = rightsubtree[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                tree.push_back(node);
            }
        }
    }
    return tree;
}
void preo(Node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preo(root->left);
    preo(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<Node*>total = construct(1,4);
    For(i,total.size())
    {
        cout<<(i+1)<<" ";
        preo(total[i]);
        cout<<endl;
    }
    return 0;
}