#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a) for(int i = 0;i<a;i++)
#define For(i,a,b) for(int i = a; i < b ;i++)
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
int height(Node* root)
{
    if(!root)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l,r)+1;
}
bool heightbalance(Node* root)
{
	if(root == NULL)
	{
		return true;
	}
	if(heightbalance(root->left) == false)
		return false;
	if(heightbalance(root->right) == false)
		return false;
	int l = height(root->left);
	int r = height(root->right);
	if(abs(l-r) <= 1)
	{
		return true;
	}
	return false;
}
bool isbalance(Node* root,int *h)
{
	if(root == NULL)
	{
		return true;
	}
	int lh = 0,rh = 0;
	if(isbalance(root->left,&lh) == false)
		return false;
	if(isbalance(root->right,&rh) == false)
		return false;
	*h = max(lh,rh) + 1;
	if(abs(lh-rh) <= 1)
		return true;
	return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
	if(heightbalance(root))
		cout<<"True"<<endl;
	else
		cout<<"Fasle"<<endl;
    return 0;
}

