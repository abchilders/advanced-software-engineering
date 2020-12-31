// Rotate List
// Link: https://leetcode.com/problems/rotate-list/submissions/

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
    ListNode* rotateRight(ListNode* head, int k) {
        // 0 or 1 nodes 
        if(head == nullptr || head->next == nullptr)
        {
            return head; 
        }
        
        // 2+ nodes 
        // get the length of the linked list and use that to 
        // calculate how far apart our pointers need to be
        int length = getLength(head); 
        int gap = k % length; 
        if (gap == 0)
        {
            return head; 
        }
        
        // start moving the end pointer away from the start
        ListNode* old_end = head; 
        ListNode* new_end = head; 
        for(int i = 0; i < gap; i++)
        {
            old_end = old_end->next; 
        }
        
        // then move the two pointers up until we reach the end 
        // of the original linked list 
        while(old_end->next != nullptr)
        {
            old_end = old_end->next; 
            new_end = new_end->next; 
        }
        
        // now cut the linked list in two and move the end 
        // portion of the list to the start 
        old_end->next = head; 
        ListNode* new_head = new_end->next; 
        new_end->next = nullptr; 
        return new_head; 
    }
    
    // returns the length of the given linked list 
    int getLength(ListNode* head)
    {
        int len = 0; 
        ListNode* itr = head; 
        while(itr != nullptr)
        {
            len++; 
            itr = itr->next; 
        }
        return len; 
    }
};