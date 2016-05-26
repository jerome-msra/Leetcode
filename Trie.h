//
//  Trie.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef Trie_h
#define Trie_h

#include "DataStructure.h"

using namespace std;

/*********************************** 208. Implement Trie (Prefix Tree) **************************************/

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->next[word[i]-'a'] == nullptr) {
                node->next[word[i]-'a'] = new TrieNode();
            }
            node = node->next[word[i]-'a'];
        }
        node->isWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * result = find(word);
        return result!=nullptr && result->isWord;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
    
private:
    TrieNode * find(string key) {
        TrieNode * node = root;
        for (int i = 0; node != nullptr && i < key.length(); i++) {
            node = node->next[key[i]-'a'];
        }
        
        return node;
    }
    
private:
    TrieNode* root;
};

#endif /* Trie_h */
