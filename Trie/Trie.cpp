#include <iostream>
#include <vector>
using namespace std;

class Trie {
private:
    bool isEnd;
    vector<Trie*> children;
public:
    Trie() : isEnd(false), children(26, NULL){

    }
    
    void insert(string word) {
        Trie* node = this;
        int size = word.size();
        for(int i=0; i<size; i++){
            char c = word[i];
            if(node->children[c-'a'] == NULL){
                node->children[c-'a'] = new Trie();
            }
            node = node->children[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        int size = word.size();
        for(int i=0; i<size; i++){
            char c = word[i];
            if(node->children[c-'a'] == NULL)
                return false;
            else
                node = node->children[c-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        int size = prefix.size();
        for(int i=0; i<size; i++){
            char c = prefix[i];
            if(node->children[c-'a'] == NULL)
                return false;
            else
                node = node->children[c-'a'];
        }
        return true;
    }
};
int main()
{
    Trie tree;
    tree.insert("apple");
    cout << tree.search("apple") << endl;
    cout << tree.search("app") << endl;
    cout << tree.startsWith("app") << endl;
    tree.insert("app");
    cout << tree.search("app") << endl;
    return 0;
}


