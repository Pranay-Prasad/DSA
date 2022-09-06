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
Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}
void inoreder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    inoreder(root->left);
    inoreder(root->right);
}
bool searchkey(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (root->data < key)
    {
        return searchkey(root->right, key);
    }
    return searchkey(root->left, key);
}
Node* inordersucc(Node* root)
{
    Node* curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node* deleteBST(Node* root,int key)
{
    if(key < root->data)
    {
        root->left = deleteBST(root->left,key);
    }
    else if(key > root->data)
    {
        root->right = deleteBST(root->right,key);
    }
    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }
    return root;
}
Node* deleteLeaf(Node* root){
    if(!root->left && !root->right){
        return NULL;
    }
    root->left = deleteLeaf(root->left); 
    root->right = deleteLeaf(root->right); 
    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);
    inoreder(root);
    Node* ans = deleteBST(root,7);
    // root = deleteLeaf(root);
    cout<<endl;
    inoreder(ans);
    return 0;
}