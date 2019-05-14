#include<iostream>
#include<string>
#include<vector>

using namespace std;

class TrieNode
{
public:
    char data;
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode(char c)
    {
        data=c;

        for(int i=0;i<26;++i)
            children.push_back(NULL);

        isTerminal=false;
    }
};

class Trie
{
public:

    TrieNode* root;

    Trie()
    {
        root=new TrieNode('\0');
    }

    void insert(string);
    void insertH(TrieNode*,string);

    bool search(string);
    bool searchH(TrieNode*,string);

    void remove(string);
    void  removeH(TrieNode*,string);

};

void Trie::insertH(TrieNode* root, string word)
{
    if(word=="")
    {
        root->isTerminal=true;
        return;
    }

    int index=word[0]-'a';
    TrieNode* child;

    if(root->children[index])
        child=root->children[index];

    else
    {
        child=new TrieNode(word[0]);
        root->children[index]=child;
    }

    insertH(child,word.substr(1));
}
void Trie::insert(string word)
{
    insertH(root,word);
}

bool Trie::searchH(TrieNode* root, string word)
{
    if(word=="") return root->isTerminal;

    int index=word[0]-'a';

    if(root->children[index])
        return searchH(root->children[index],word.substr(1));
    else return false;


}
bool Trie::search(string word)
{
    return searchH(root,word);
}

void Trie::removeH(TrieNode* root, string word)
{
    if(word=="")
    {
        root->isTerminal=false;
        return;
    }

    int index=word[0]-'a';
    TrieNode* child;

    if(root->children[index])
    {
        child=root->children[index];
        removeH(child,word.substr(1));
    }
    else return;

    if(child->isTerminal)
    {
        for(int i=0;i<26;++i)
        {
            if(child->children[i])
             return;
        }

        delete child;
        root->children[index]=NULL;
    }
}
void Trie::remove(string word)
{
    removeH(root,word);
}
int main()
{
   Trie T;
   T.insert("shubham");
   if(T.search("shubham"))
    cout<<endl<<"Yes, it's found";
   T.remove("shubham");
   if(T.search("shubham"))
    cout<<"Found again";
}
