//
//  WordLadder.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef WordLadder_h
#define WordLadder_h

#include "DataStructure.h"

using namespace std;

/****************************************** 127. Word Ladder ******************************************/

void findNeighbors (string word, unordered_set<string> & wordList, queue<string> & toVisit) {
    for (int p = 0; p < word.length(); p++) {
        char c = word[p];
        for (int k = 0; k < 26; k++) {
            if (k != c - 'a') {
                word[p] = 'a' + k;
                if (wordList.count(word) > 0) {
                    toVisit.push(word);
                    wordList.erase(word);
                }
            }
        }
        word[p] = c;
    }
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    wordList.insert(endWord);
    queue<string> toVisit;
    findNeighbors(beginWord, wordList, toVisit);
    int ladder = 2;
    while (!toVisit.empty()) {
        for (int i = 0; i < toVisit.size(); i++) {
            string curr = toVisit.front();
            toVisit.pop();
            if (curr == endWord) {
                return ladder;
            }
            findNeighbors(curr, wordList, toVisit);
        }
        ladder++;
    }
    
    return 0;
}

#endif /* WordLadder_h */
