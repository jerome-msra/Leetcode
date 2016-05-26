//
//  UpsideDown.h
//  LeetCode
//
//  Created by Jerome on 5/14/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef UpsideDown_h
#define UpsideDown_h

#include "DataStructure.h"

using namespace std;

TreeNode * upsideDownHelper(TreeNode * root, TreeNode * left, TreeNode * right) {
    if (left==nullptr) return root;
    TreeNode * leftleft = left->left;
    TreeNode * leftright = left->right;
    left->left = right;
    left->right = root;
    return upsideDownHelper(left, leftleft, leftright);
}

TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode * result = upsideDownHelper(root, root->left, root->right);
    return result;
}


#endif /* UpsideDown_h */
