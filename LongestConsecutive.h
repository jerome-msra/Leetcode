//
//  LongestConsecutive.h
//  LeetCode
//
//  Created by Jerome on 5/19/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LongestConsecutive_h
#define LongestConsecutive_h

#include "DataStructure.h"

using namespace std;

void longestHelper(unordered_map<TreeNode*, int> & mymap, TreeNode * root) {
    if (root==nullptr) {
        mymap[root] = 0;
        return;
    }
    
    longestHelper(mymap, root->left);
    longestHelper(mymap, root->right);
    
    int leftdist = (root->left==nullptr || root->val - root->left->val != -1) ? 1 : mymap[root->left]+1;
    int rightdist = (root->right==nullptr || root->val - root->right->val != -1) ? 1 : mymap[root->right]+1;
    
    mymap[root] = max(leftdist, rightdist);
    
    return;
}

int longestConsecutive(TreeNode* root) {
    unordered_map<TreeNode *, int> mymap;
    longestHelper(mymap, root);
    int result = 1;
    for (auto it : mymap) {
        result = max(result, it.second);
    }
    return result;
}

#endif /* LongestConsecutive_h */
