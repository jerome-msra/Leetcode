//
//  WordLadderII.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef WordLadderII_h
#define WordLadderII_h

#include "DataStructure.h"

using namespace std;

void output(unordered_map<string, unordered_set<string>> & graph, string & startWord, string & endWord, vector<string> current, vector<vector<string>> & result) {
    if (endWord == startWord) {
        reverse(current.begin(), current.end());
        result.push_back(current);
        reverse(current.begin(), current.end());
        return;
    }
    else {
        for (auto w : graph[endWord]) {
            current.push_back(w);
            output(graph, startWord, w, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    wordList.insert(endWord);
    string word = beginWord;
    queue<string> myqueue;
    myqueue.push(word);
    vector<string> current;
    vector<vector<string>> result;
    unordered_map<string, unordered_set<string>> graph;
    while(!myqueue.empty()) {
        size_t n = myqueue.size();
        for (int i = 0; i < n; i++) {
            string str = myqueue.front();
            myqueue.pop();
            myqueue.push(str);
            wordList.erase(str);
        }
        bool found = false;
        for (int i = 0; i < n; i++) {
            string str = myqueue.front();
            myqueue.pop();
            wordList.erase(str);
            string parent = str;
            for (int s = 0; s < str.length(); s++) {
                char c = str[s];
                for (int k = 0; k < 26; k++) {
                    str[s] = 'a'+k;
                    if (str==endWord) found = true;
                    if (wordList.count(str)>0) {
                        myqueue.push(str);
                        graph[str].insert(parent);
                    }
                }
                str[s] = c;
            }
        }
        if (found) break;
    }
    current.push_back(endWord);
    output(graph, beginWord, endWord, current, result);
    
    return result;
}

#endif /* WordLadderII_h */
