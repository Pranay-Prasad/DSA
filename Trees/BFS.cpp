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
void BFS(Node* root){
    vector<vector<int>>ans;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int>temp;
        for(int i = 0; i < n;i++){
            Node* n1 = q.front();
            if(n1){
                temp.push_back(n1->data);
                q.push(n1->left);
                q.push(n1->right);
            }
        }
        ans.push_back(temp);
    }
    for(int i = 0; i < ans.size();i++){
        for(int j = 0;j < ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // BFS(root);
    map<char,int>mp = {{'c',2}};
    cout<<mp['c']<<endl;
    return 0;
}