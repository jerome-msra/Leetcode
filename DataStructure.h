//
//  DataStructure.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef DataStructure_h
#define DataStructure_h

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class TrieNode {
public:
    bool isWord;
    TrieNode* next[26];
    // Initialize your data structure here.
    TrieNode() {
        fill(next, next+26, nullptr);
        isWord = false;
    }
};



bool isPalindrome(string s) {
    size_t i = 0;
    size_t j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    
    return true;
}

#endif /* DataStructure_h */
