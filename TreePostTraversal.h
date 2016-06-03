//
//  TreePostTraversal.h
//  LeetCode
//
//  Created by Jerome on 6/3/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef TreePostTraversal_h
#define TreePostTraversal_h

#include "DataStructure.h"

using namespace std;

vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> mystack;
    if (root!=nullptr) mystack.push(root);
    unordered_set<TreeNode*> visited;
    visited.insert(root);
    vector<int> result;
    while(!mystack.empty()) {
        TreeNode * topnode = mystack.top();
        if (topnode->left!=nullptr && visited.count(topnode->left)==0) {
            mystack.push(topnode->left);
            continue;
        }
        if (topnode->right!=nullptr && visited.count(topnode->right)==0) {
            mystack.push(topnode->right);
            continue;
        }
        if (topnode->left==nullptr && topnode->right==nullptr) {
            result.push_back(topnode->val);
            visited.insert(topnode);
            mystack.pop();
            if (!mystack.empty()) {
                TreeNode * next = mystack.top()->right;
                if (visited.count(next)==0) mystack.push(next);
            }
            continue;
        }
        bool left = topnode->left==nullptr || (topnode->left!=nullptr && visited.count(topnode->left)>0);
        bool right = topnode->right==nullptr || (topnode->right!=nullptr && visited.count(topnode->right)>0);
        if (left && right) {
            result.push_back(topnode->val);
            visited.insert(topnode);
            mystack.pop();
        }
    }
    
    return result;
}

#endif /* TreePostTraversal_h */
