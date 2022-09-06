#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertathead(node* &head,int val)
{
    node* n =new node(val);
    n->next = head;
    if(head!=NULL)
    {
        head->prev = n;
    }
    head = n;

}
void inseartatTail(node* &head,int val)
{
    if(head==NULL)
    {
        insertathead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next= n;
    n->prev=temp;
}
void deleteathead(node* &head)
{
    node* todelete = head;
    head  = head->next;
    head->prev = NULL;
    delete todelete;
}
void deleteion(node* &head,int  pos)
{
    if(pos == 1)
    {
        deleteathead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL)
    {
        temp->next->prev =  temp->prev;
    }
    delete temp;
}
void display(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int length(node* head)
{
    int l = 0;
    node* temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
node* kappend(node* &head,int k)
{
    node* newhead;
    node* newtail;
    node* tail = head;
    int l = length(head);
    k=k%l;
    int count = 1;
    while (tail->next != NULL)
    {
        if(count==l-k)
        {
            newtail = tail; 
        }
        if(count == l-k+1)
        {
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node* head = NULL;
    inseartatTail(head,1);
    inseartatTail(head,2);
    inseartatTail(head,3);
    inseartatTail(head,4);
    inseartatTail(head,5);
    inseartatTail(head,6);
    display(head);
    node* newhead = kappend(head,3);
    display(newhead);
    return 0;
}