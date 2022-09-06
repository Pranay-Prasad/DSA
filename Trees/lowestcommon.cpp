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
bool getpath(Node* root,vector<int> &vec,int key)
{
	if(root == NULL)
	{
		return false;
	}
	vec.push_back(root->data);
	if(root->data == key)
	{
		return true;
	}
	if(getpath(root->left,vec,key) || getpath(root->right,vec,key))
	{
		return true;
	}
	vec.pop_back();
	return false;
}
Node* LCA(Node* root,int a,int b)
{
	vector<int>vec1,vec2;
	if(!getpath(root,vec1,a) || !getpath(root,vec2,b))
		return NULL;
	int p;
	for(p = 0; p < vec1.size() && vec2.size();p++)
	{
		if(vec1[p] != vec2[p])
			break;
	}
	Node* h = new Node(vec1[p-1]);
	cout<<h->data<<endl;
	return h;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = new Node(-3);
    root->left = new Node(0);
	root->right = new Node(3);
	root->left->left = new Node(-2);
	root->left->left->left = new Node(8);
	root->left->right = new Node(4);
    int n1 = 8;
    int n2 = 0;
    Node* lca = LCA(root,n1,n2);
	cout<<lca->data<<endl;
    return 0;
}
