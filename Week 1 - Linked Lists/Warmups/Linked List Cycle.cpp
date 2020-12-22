// https://leetcode.com/problems/linked-list-cycle/

/**
* Given head, the head of a linked list, determine if the linked list has a 
* cycle in it.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // time: O(N), space: O(1) 
        
        // list size 0 or 1 
        if (head == nullptr || head->next == nullptr) {
            return false; 
        }
        
        // list size 2+: using tortoise and hare method of detecting linked list 
        ListNode *tortoise = head; 
        ListNode *hare = head->next; 

        while(tortoise != hare) {
            // if the hare finds a nullptr somewhere, the list ends at some point
            if (hare == nullptr || hare->next == nullptr) {
                return false; 
            }
            tortoise = tortoise->next; 
            hare = hare->next->next; 
        }
        // if tortoise == hare, then there was a loop somewhere enabling 
        //      hare to catch up to tortoise 
        return true; 
    }
};