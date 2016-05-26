//
//  ReorderList.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ReorderList_h
#define ReorderList_h

#include "DataStructure.h"

using namespace std;

/****************************************** 143 REORDER LIST ******************************************/

void reorderList(ListNode* head) {
    unordered_map<int, ListNode*> nodemap;
    int idx = 0;
    ListNode * node = head;
    while(node!=nullptr) {
        nodemap[idx++] = node;
        node = node->next;
    }
    idx--;
    if (idx == 1) return;
    
    int startId = idx / 2 + 1;
    for (int i = idx; i >= startId; i--) {
        ListNode * node = nodemap[i];
        ListNode * prevNode = nodemap[i-1];
        ListNode * insNode = nodemap[idx-i];
        ListNode * insNextNode = nodemap[idx-i+1];
        prevNode->next = nullptr;
        node->next = insNextNode;
        insNode->next = node;
    }
    
    return;
}

#endif /* ReorderList_h */
