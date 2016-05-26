//
//  ListIntersection.h
//  LeetCode
//
//  Created by Jerome on 5/13/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ListIntersection_h
#define ListIntersection_h

#include "DataStructure.h"

using namespace std;

/****************************************** LIST INTERSECTION ******************************************/

ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode * p = headA;
    while(p->next != nullptr) p = p->next;
    p->next = headB; // make a cycle
    
    ListNode * fast = headA;
    ListNode * slow = headA;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    if (slow != fast) return nullptr;
    
    slow = headB;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    ListNode * intersection = slow;
    
    p->next = nullptr;
    
    return intersection;
}

#endif /* ListIntersection_h */
