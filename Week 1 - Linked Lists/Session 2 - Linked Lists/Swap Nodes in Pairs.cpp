// Swap Nodes in Pairs
// Link: https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        // 0 or 1 nodes 
        if (head == nullptr || head->next == nullptr)
        {
            return head; 
        }
        
        // 2+ nodes: create pointers that will point to the nodes to be swapped,
        // and reassign the head 
        ListNode* first = head; 
        ListNode* second = first->next; 
        ListNode* dummy = new ListNode(-1, head); 
        ListNode* before = dummy; 
        
        // traverse through the list  
        while(first != nullptr && first->next != nullptr)
        {
            // move up second pointer 
            second = first->next; 
            
            // swap nodes
            before->next = second; 
            first->next = second->next; 
            second->next = first; 
            
            // increment pointers 
            before = first; 
            first = first->next;
        }
        
        return dummy->next; 
    }
};