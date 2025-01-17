#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++)
        {
            int j = word[i] - 'a';
            if (p->children[j] == NULL)
            {
                p->children[j] = new TrieNode();
            }
            p = p->children[j];
        }
        p->isEnd = true;
    }

    TrieNode *startsWithP(string prefix)
    {
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int j = prefix[i] - 'a';
            if (p->children[j] == NULL)
            {
                return NULL;
            }
            p = p->children[j];
        }
        return p;
    }

    bool search(string word)
    {
        TrieNode *p = startsWithP(word);
        return p == NULL ? false : p->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *p = startsWithP(prefix);
        return p != NULL;
    }
};

int main()
{
    Trie *obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    obj->insert("app");
    cout << obj->search("app") << endl;
    return 0;
}