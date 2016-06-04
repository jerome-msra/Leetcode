//
//  PopulatingNextRightPointersinEachNodeII.h
//  LeetCode
//
//  Created by Jerome on 6/3/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef PopulatingNextRightPointersinEachNodeII_h
#define PopulatingNextRightPointersinEachNodeII_h

#include "DataStructure.h"

using namespace std;

void connect(TreeLinkNode *root) {
    TreeLinkNode * current = root;
    TreeLinkNode * head = nullptr, * tail = nullptr;
    while(current) {
        if (current->left) {
            if (tail) { tail->next = current->left; tail = tail->next; }
            else { head = current->left; tail = head; }
        }
        if (current->right) {
            if (tail) { tail->next = current->right; tail = tail->next; }
            else { head = current->right; tail = head; }
        }
        if (current->next) {
            current = current->next;
        }
        else {
            current = head;
            head = nullptr, tail = nullptr;
        }
    }
    return;
}

#endif /* PopulatingNextRightPointersinEachNodeII_h */
