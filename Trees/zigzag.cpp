#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
vector<int> ans;
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
void zigzag(Node *root)
{
    if(!root)
        return;
    stack<Node *> curr;
    stack<Node *> next;
    bool lefttright = true;
    curr.push(root);
    while (!curr.empty())
    {
        Node *temp = curr.top();
        curr.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";
            //leftto right
            if (lefttright)
            {
                if (temp->left)
                    next.push(temp->left);
                if (temp->right)
                    next.push(temp->right);
            }
            //right to left
            else
            {
                if (temp->right)
                    next.push(temp->right);
                if (temp->left)
                    next.push(temp->left);
            }
        }
        if(curr.empty())
        {
            lefttright = !lefttright;
            swap(curr,next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    zigzag(root);
    return 0;
}