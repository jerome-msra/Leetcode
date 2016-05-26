//
//  ReverseNodesKGroup.h
//  LeetCode
//
//  Created by Jerome on 5/26/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef ReverseNodesKGroup_h
#define ReverseNodesKGroup_h

#include "DataStructure.h"

using namespace std;

/************************** 25. Reverse Nodes in k-Group *************************/

ListNode* reverseList(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode * tail = head;
    while (tail->next != NULL) tail = tail->next;
    ListNode * node = head;
    tail->next = node;
    ListNode * newNode = node->next;
    node->next = NULL;
    while (newNode != tail) {
        ListNode * tempNode = newNode->next;
        newNode->next = tail->next;
        tail->next = newNode;
        newNode = tempNode;
    }
    return tail;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 1) return head;
    int length = 0;
    ListNode * node = head;
    while(node!=nullptr) {node = node->next; length++;}
    if (k > length) return head;
    int pos = 0;
    node = head;
    ListNode * fakeHead = new ListNode(0);
    fakeHead->next = head;
    ListNode * prev = fakeHead;
    while(node!=nullptr) {
        ListNode * startnode = node;
        while(node!=nullptr && pos < k-1) {node = node->next; pos++;}
        if (node!=nullptr) {
            ListNode * nextnode = node->next;
            node->next = nullptr;
            ListNode * revNode = reverseList(startnode);
            ListNode * lastnode = revNode;
            while(lastnode->next!=nullptr) lastnode = lastnode->next;
            prev->next = revNode;
            lastnode->next = nextnode;
            prev = lastnode;
            node = nextnode;
            pos = 0;
        }
    }
    return fakeHead->next;
}

#endif /* ReverseNodesKGroup_h */
