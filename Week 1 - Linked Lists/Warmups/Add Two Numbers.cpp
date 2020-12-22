// https://leetcode.com/problems/add-two-numbers/

/**
* You are given two non-empty linked lists representing two non-negative 
* integers. The digits are stored in reverse order, and each of their nodes 
* contains a single digit. Add the two numbers and return the sum as a linked 
* list.
* You may assume the two numbers do not contain any leading zero, except the 
* number 0 itself.
*/

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

// time: O(N)
// space: O(N)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // iterate over each place value, adding together like places,
        // and add a new node for that place value to the result 
        ListNode* dummy_head = new ListNode(-1); 
        ListNode* tail = dummy_head; 
        ListNode* l1_itr = l1;
        ListNode* l2_itr = l2; 
        int carry = 0; 
        
        while(l1_itr != nullptr || l2_itr != nullptr)
        {
            // add the carry digit from last iteration
            int sum = carry; 
            
            // get digit at the current place value 
            if (l1_itr != nullptr)
            {
                sum += l1_itr->val; 
                l1_itr = l1_itr->next; 
            }
            if (l2_itr != nullptr)
            {
                sum += l2_itr->val; 
                l2_itr = l2_itr->next; 
            }
            
            // then set carry digit and create a new node representing the current 
            // digit in the result list 
            carry = sum / 10; 
            tail->next = new ListNode(sum % 10); 
            tail = tail->next;
        }
        // tie up final carry bit 
        if(carry > 0)
        {
            tail->next = new ListNode(carry); 
        }
        
        return dummy_head->next; 
    }
};