#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
class node
{
public:
    int data;
    node *next;
    node(int val,node* nxt = NULL)
    {
        data = val;
        next = nxt;
    }
};
void insertAttail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
int get_length(node *head)
{
    int l = 0;
    while (head)
    {
        l++;
        head = head->next;
    }
    return l;
}
node* oddEvenList(node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    int n = get_length(head);
    if (n%2 == 0)
    {
        cout<<"n: "<<n<<endl;
        n = (n / 2) - 1;
    }
    else
        n = n / 2;
    node *dummy1 = new node(0, head);
    node *dummy2 = head->next;
    node *h1 = head;
    node *h2 = dummy2;
    for (int i = 0; i < n; i++)
    {
        cout<<"WORK"<<endl;
        node *temp = h2->next;
        h2->next = h2->next->next;
        h2 = h2->next;
        h1->next = temp;
        h1 = h1->next;
    }
    h1->next = dummy2;
    return dummy1->next;
}
int solve(node *head)
{
    int l = 0;
    while (head)
    {
        l++;
        head = head->next;
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *head = NULL;
    insertAttail(head, 1);
    insertAttail(head, 2);
    insertAttail(head, 3);
    insertAttail(head, 4);
    insertAttail(head, 5);
    insertAttail(head, 6);
    node *head2 = NULL;
    insertAttail(head, 5);
    insertAttail(head, 4);
    insertAttail(head, 3);
    insertAttail(head, 7);
    node *head3 = NULL;
    insertAttail(head, 5);
    vector<node*>vec;
    vec.push_back(head);
    vec.push_back(head2);
    vec.push_back(head3);
    for(int i = 0; i < 3;i++){
        node* root = vec[i];
        cout<<"root: "<<root->data<<endl;
        while(root){
            cout<<root->data<<" ";
            root = root->next;
        }
        cout<<"\n";
        root = NULL;
    }
    return 0;
}