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
void larges(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	int level = 0;
	vi ans;
	ans.push_back(root->data);
	while(!q.empty())
	{
		Node* node = q.front();
		q.pop();
		if(node == NULL)
		{
			level++;
		}
		if(node != NULL)
		{
			int max = 
		}
	}
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<leaves(root)<<endl;
    return 0;
}
