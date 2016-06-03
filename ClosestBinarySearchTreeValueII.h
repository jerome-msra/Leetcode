//
//  ClosestBinarySearchTreeValueII.h
//  LeetCode
//
//  Created by Jerome on 6/3/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ClosestBinarySearchTreeValueII_h
#define ClosestBinarySearchTreeValueII_h

#include "DataStructure.h"

using namespace std;

void closestTraverse(TreeNode * root, priority_queue<pair<double, int>> & myqueue, double target, int k) {
    if (root==nullptr) return;
    myqueue.push(make_pair(fabs(target-(double) root->val), root->val));
    if (myqueue.size()>k) {
        myqueue.pop();
    }
    closestTraverse(root->left, myqueue, target, k);
    closestTraverse(root->right, myqueue, target, k);
}

vector<int> closestKValues(TreeNode* root, double target, int k) {
    priority_queue<pair<double, int>> myqueue;
    closestTraverse(root, myqueue, target, k);
    vector<int> result;
    while(!myqueue.empty()) {
        result.push_back(myqueue.top().second);
        myqueue.pop();
    }
    return result;
}

#endif /* ClosestBinarySearchTreeValueII_h */
