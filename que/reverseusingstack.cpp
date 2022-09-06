#include<bits/stdc++.h>
using namespace std;
void reverse(string s)
{
    stack<string>st;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i<s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
    
}
void inseartAtBottom(stack<int> & st,int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    inseartAtBottom(st,ele);

    st.push(topele);
}
void reversestack(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reversestack(st);
    inseartAtBottom(st,ele);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reversestack(st);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}