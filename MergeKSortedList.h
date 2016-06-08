//
//  MergeKSortedList.h
//  LeetCode
//
//  Created by Jerome on 6/7/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef MergeKSortedList_h
#define MergeKSortedList_h

#include "DataStructure.h"

using namespace std;

// This is a min heap, but must use greater comparison
struct mycompare {
    bool operator()(ListNode * a, ListNode * b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode * dummy = new ListNode(0);
    ListNode * prev = dummy;
    for (auto it = lists.begin(); it!=lists.end();) {
        ListNode * t = *it;
        if (t!=nullptr) it++;
        else {
            it = lists.erase(it);
        }
    }
    
    priority_queue<ListNode*, vector<ListNode*>, mycompare> myqueue(lists.begin(), lists.end());
    while(!myqueue.empty()) {
        ListNode * next = myqueue.top();
        prev->next = next;
        prev = next;
        myqueue.pop();
        if (next->next!=nullptr) {
            myqueue.push(next->next);
        }
    }
    
    return dummy->next;
}

#endif /* MergeKSortedList_h */
