//
//  LowestCommonAncester.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LowestCommonAncester_h
#define LowestCommonAncester_h

#include "DataStructure.h"

using namespace std;

/********************* 236 LOWEST COMMON ANCESTOR OF A BINARY TREE ************************/


bool dfs(vector<TreeNode*> & path, TreeNode * node, TreeNode * target) {
    path.push_back(node);
    if (node == target) return true;
    if (node->left)  {
        if (dfs(path, node->left, target)) return true;
    }
    if (node->right) {
        if (dfs(path, node->right, target)) return true;
    }
    path.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path_p, path_q;
    dfs(path_p, root, p);
    dfs(path_q, root, q);
    size_t i = 0;
    while(i < min(path_p.size(), path_q.size()) && path_p[i] == path_q[i]) {
        i++;
    }
    
    return path_p[i-1];
}

#endif /* LowestCommonAncester_h */
