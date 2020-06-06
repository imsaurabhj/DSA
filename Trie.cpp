#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode* child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};
class Trie
{
    private:

        TrieNode* root;
    
    public:
    Trie()
    {
        root= new TrieNode;
    }
    bool search(string s)
    {
        int n=s.size(),i=0;
        TrieNode* curr=root;
        while(i<n)
        {
            int c_index=s[i]-'a';
            if(curr->child[c_index]==NULL)
                return false;
            else
            {
                curr=curr->child[c_index]; i++;
            }
        }
        if(curr->isEnd)
            return true;
        else
            return false;
    }       
    void insert(string str)
    {
        int n=str.size();
        TrieNode* curr=root;
        int i=0;
        while(i<n)
        {   int c_index=str[i]-'a';
            if(curr->child[c_index]==NULL)
            {
                TrieNode* temp= new TrieNode;
                curr->child[c_index]=temp;
                curr=temp; 
                i++; 
            }
            else
            {
                curr=curr->child[c_index];
                i++;
            }
        }
        curr->isEnd=true;
    }
    void printTriehelper(TrieNode* curr, string s)
    {
        if(curr->isEnd==true)
            cout<<s<<endl;
        for(int i=0;i<26;i++)
        {
            if(curr->child[i]!=NULL)
            {   string temp=s+(char)(i+'a');
                printTriehelper(curr->child[i],temp);
            }
        }
    }
    void printTrie()
    {   
        printTriehelper(root,"");
    }

};


int main()
{
    Trie dict;
    dict.insert("bat");
    dict.insert("bad");
    dict.insert("zoo");
    dict.insert("geeks");
    dict.insert("cat");
    dict.insert("cut");
    dict.insert("geek");
    return 0;
}