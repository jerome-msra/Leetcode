//
//  LevelOrder_I.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LevelOrder_I_h
#define LevelOrder_I_h

#include "DataStructure.h"

using namespace std;

/****************************************** LEVEL ORDER I ******************************************/

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<TreeNode*> myqueue;
    myqueue.push(root);
    while(!myqueue.empty())
    {
        vector<int> currentLevel;
        vector<TreeNode *> tmp;
        while(!myqueue.empty())
        {
            TreeNode * t = myqueue.front();
            myqueue.pop();
            currentLevel.push_back(t->val);
            tmp.push_back(t);
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            TreeNode * t = tmp[i];
            if (t->left) myqueue.push(t->left);
            if (t->right) myqueue.push(t->right);
        }
        
        result.push_back(currentLevel);
    }
    
    return result;
}

#endif /* LevelOrder_I_h */
