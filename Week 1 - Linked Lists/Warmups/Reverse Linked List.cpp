// https://leetcode.com/problems/reverse-linked-list/

// Reverse a singly linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // RECURSIVE SOLUTION - time O(N), space O(N) 
        // (sub)list size 0 or 1-- current node is last item in list, 
        //      or list DNE. So return new head  
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }
        
        // list size 2+ 
        // call this function on the sublist whose head is next; 
        //      the new list head should be the last element in the list 
        ListNode* new_head = reverseList(head->next); 
        // make the next item in the list point backwards to us
        head->next->next = head; 
        // and erase our link to the next item 
        head->next = nullptr; 
        // float new head back up the call stack 
        return new_head; 
        
        // ITERATIVE SOLUTION - time O(N), space O(1)
        /*
        // list size 0 or 1 
        if(head == nullptr || head->next == nullptr) {
            return head; 
        }
        
        // list size 2+ 
        ListNode* prev = nullptr; 
        ListNode* curr = head; 
        ListNode* next = nullptr; 
        while(curr != nullptr) {
            // remember this node's old next 
            next = curr->next; 
            // reverse this node's link 
            curr->next = prev; 
            // now move on to the old next item 
            prev = curr; 
            curr = next; 
        }
        return prev; 
        */
    }
};