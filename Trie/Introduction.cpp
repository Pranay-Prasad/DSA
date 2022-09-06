
#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int cntEndwith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    void increaseEnd(){
        cntEndwith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndwith--;
    }
    void reduceprefix(){
        cntPrefix--;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root= new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node= node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualTp(string &word){
        Node* node = root;
        for(int i = 0; i <word.size();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else return 0;
        }
        return 0;
    }
    int countWordStartingWith(string &word){

    }
    void erase(string &word){

    }

};
int main()
{
    
    return 0;
}