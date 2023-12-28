/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/

//Solution:
class TrieNode
{
    public:
    char ch;
    TrieNode* child[26];
    bool isEnd;

    TrieNode(char val)
    {
        this->ch=val;
        for(int i=0;i<26;i++)child[i]=NULL;
        this->isEnd=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode('\0');
    }
    void inserting(TrieNode* root,string word){
        if(word.length()==0){
            root->isEnd=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* temp;
        if(root->child[index] != NULL){
            temp=root->child[index];
        }
        else{
            temp=new TrieNode(word[0]);
            root->child[index]=temp;
            temp=root->child[index];
        }
        inserting(temp,word.substr(1));
    }
    void insert(string word) {
        inserting(root,word);
    }

    bool searching(TrieNode* root,string word){
        if(word.length()==0)return root->isEnd;
        int index=word[0]-'a';
        if(root->child[index] != NULL){
            return searching(root->child[index],word.substr(1));
        }
        return false;
    }
    bool search(string word) {
        return searching(root,word);
    }
    
    bool startsChecking(TrieNode* root,string word){
        if(word.length()==0)return true;
        int index=word[0]-'a';
        if(root->child[index] != NULL){
            return startsChecking(root->child[index],word.substr(1));
        }
        return false;
    }
    bool startsWith(string prefix) {
       return startsChecking(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
