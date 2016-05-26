//
//  AddSearchWordsDesign.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef AddSearchWordsDesign_h
#define AddSearchWordsDesign_h

#include "DataStructure.h"

using namespace std;

/************************ 211. Add and Search Word - Data structure design *****************************/

class WordDictionary {
public:
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->next[word[i]-'a'] == nullptr) {
                node->next[word[i]-'a'] = new TrieNode();
            }
            node = node->next[word[i]-'a'];
        }
        node->isWord = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        //TrieNode * node = root;
        return dfsTrieWord(word, 0, root);
    }
    
    bool dfsTrieWord(string & word, int i, TrieNode * node) {
        if (i == word.length() && node->isWord) return true;
        if (word[i] != '.') {
            node = node->next[word[i]-'a'];
            if (node == nullptr) return false;
            if (node->isWord) return true;
            return dfsTrieWord(word, i+1, node);
        }
        else {
            for (int n = 0; n < 26; n++) {
                TrieNode * nextnode = node->next[n];
                if (nextnode == nullptr) continue;
                if (dfsTrieWord(word, i+1, nextnode)) return true;
            }
        }
        
        return false;
    }
    
    TrieNode * root;
};

#endif /* AddSearchWordsDesign_h */
