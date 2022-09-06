#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
// void insertathead(node* &head,int val)
// {
//     node* n =new node(val);
//     n->next = head;
//     head = n;
// }
void insertAttail(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=n;
}
void display(node* head)
{
    node* temp=head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<endl;
}
// bool search(node* head,int key)
// {
//     node* temp = head;
//     while (temp != NULL)
//     {
//         if(temp->data == key)
//         {
//             return true;
//         }
//         temp = temp->next;
//     }
//     return false;
// }
// void deleteion(node* &head,int val)
// {
//     node* temp = head;
//     while (temp->next->data != val)
//     {
//         temp = temp->next;
//     }
//     node* todelete = temp->next;
//     temp->next = temp->next->next;
//     delete todelete;
// }
node* reverse(node* &head)
{
    node* prev = NULL;
    node* curr = head;
    node* nextpr;
    while (curr!=NULL)
    {
        nextpr = curr->next;
        curr->next = prev;
        prev = curr;
        curr=nextpr;
    }
    return prev;
}
void makeCycle(node* &head,int pos)
{
    node* temp=head;
    node* startNode;


    int count = 1;
    while (temp->next != NULL)
    {
        if(count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
void remove_cycle(node* &head)
{
    node* slow = head;
    node* fast = head;
    do
    {
        slow  = slow->next;
        fast  = fast->next->next;
    } while (fast != slow);
    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
bool dectect_cycle(node* &head)
{
    node* slow=head;
    node* fast=head;
    while (fast!= NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast=fast->next->next;

        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}
int lengthll(node* head){
    int l = 0;
    while(head != NULL){
        l++;
        head = head->next;
    }
    return l;
}
string get_b(node* head){
    string s = "";
    while(head != NULL){
        s += to_string(head->data);
        head = head->next;
    }
    return s;
}
int main()
{
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);
    insertAttail(head,6);
    string s = get_b(head);
    cout<<s<<endl;
    return 0;
}