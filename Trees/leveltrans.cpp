#include <bits/stdc++.h>
using namespace std;
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
void levelor(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
int sum(Node *root,int k)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    double level = 0;
    double sum = 0;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if(node == NULL)
        {
            cout<<sum<<" "<<level<<" "<<(double)sum/level<<endl;
            sum= 0;
            level = 0;
        }
        if (node != NULL)
        {
            level++;
            sum += node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    return sum;
}
pair<int,int> solve2(Node* root){
    return {1,2};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->left->left = new Node(15);
    root->left->right = new Node(7);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    /*
            1 => 1
           / \
          2   3 => 5
         / \ / \
        4  5 6  7 => 23
    */
    pair<int,int> ans = solve2(root);
    cout<<max(ans.first,ans.second)<<endl;
    return 0;
}