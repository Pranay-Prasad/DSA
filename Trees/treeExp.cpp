#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// vector<string> solve(Node* root){
//     vector<string>ans;
//     if(!root)
//         return ans;
//     string s = to_string(root->data);
//     s ++
// }
Node* solve(Node* root,Node* root2){
    if(!root)
        return NULL;
    if(root->data == root2->data){
        cout<<"YES"<<endl;
        return root;
    }
    cout<<"LOOP"<<endl;
    solve(root->left,root2);
    solve(root->right,root2);
    return NULL;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct Node *root = new Node(1);
    struct Node *root2 = new Node(2);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right= new Node(5);
    Node* jon = solve(root,root2);
    
    return 0;
}