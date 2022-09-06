#include<bits/stdc++.h>
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
void insertatHead(node* &head,int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        n->next = n;
        head  = n;
    }
        
    node* temp = head;
    while (temp->next != head)
    {
        temp=temp->next;
    }
    temp->next = n; 
    n->next = head;
    head = n;
}
void insertatTail(node* &head,int val)
{
    if(head == NULL)
    {
        insertatHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while (temp->next != head)
    {
        temp=temp->next;
    }
    temp->next = n;
    n->next = head;
}
void deleteatHead(node* &head)
{
    node* temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node* todelte = head;
    temp->next = head->next;
    head = head->next;
    delete todelte;
}
void deletion(node* &head,int pos)
{
    if(pos == 1)
    {
        deleteatHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while (count != pos-1)
    {
        temp = temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next= temp->next->next;
    delete todelete;

}
void display(node* head)
{
    node* temp = head;
    do
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}
int main()
{
    node* head = NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);
    display(head);
    insertatHead(head,5);
    display(head);
    deletion(head,1);
    display(head);
    return 0;
}