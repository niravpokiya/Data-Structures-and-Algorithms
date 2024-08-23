#include<bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    char data;
    TrieNode* child[26];
    bool isTerminating;

    TrieNode(char ch) : data(ch), isTerminating(false) {
        std::fill(child, child + 26, nullptr);
    }

    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete child[i];
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    ~Trie() {
        delete root;
    }

    void insert(const std::string& word) {
        TrieNode* tmp = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!tmp->child[index]) {
                tmp->child[index] = new TrieNode(ch);
            }
            tmp = tmp->child[index];
        }
        tmp->isTerminating = true;
    }

    bool search(const std::string& word) const {
        TrieNode* tmp = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!tmp->child[index]) {
                return false;
            }
            tmp = tmp->child[index];
        }
        return tmp->isTerminating;
    }

    bool startsWith(const std::string& prefix) const {
        TrieNode* tmp = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!tmp->child[index]) {
                return false;
            }
            tmp = tmp->child[index];
        }
        return true;
    }
};

int main(){
    Trie T;
    // action on it
}