//
//  ConvertSortedListToBST.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ConvertSortedListToBST_h
#define ConvertSortedListToBST_h

#include "DataStructure.h"

using namespace std;

/****************************** 109 CONVERT SORTED LIST INTO BINARY SEARCH TREE ******************************/

ListNode * findMedium(ListNode * left, ListNode * right) {
    ListNode * p = left;
    int length = 0;
    while(p != right) {
        p = p->next;
        length++;
    }
    length /= 2;
    int i = 0;
    p = left;
    while(i < length) {
        p = p->next;
        i++;
    }
    return p;
}

void dfs(TreeNode * & node, ListNode * left, ListNode * right) {
    if (left == right) return;
    ListNode * medium = findMedium(left, right);
    node = new TreeNode(medium->val);
    dfs(node->left, left, medium);
    dfs(node->right, medium->next, right);
}

TreeNode* sortedListToBST(ListNode* head) {
    ListNode * medium = findMedium(head, nullptr);
    TreeNode * root = new TreeNode(medium->val);
    dfs(root->left, head, medium);
    dfs(root->right, medium->next, nullptr);
    return root;
}

#endif /* ConvertSortedListToBST_h */
