// https://leetcode.com/problems/odd-even-linked-list/

/**
* Given a singly linked list, group all odd nodes together followed by the 
* even nodes. Please note here we are talking about the node number and not 
* the value in the nodes.
* You should try to do it in place. The program should run in O(1) space 
* complexity and O(nodes) time complexity.
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
// space: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return head; 
        }
        
        // keep track of the head of the even list for later
        ListNode* even_head_ptr = new ListNode(-1, head->next); 
        ListNode* odd_itr = head; 
        ListNode* even_itr = head->next; 
        
        // then iterate through the linked list
        while(odd_itr->next != nullptr || even_itr != nullptr)
        {
            // we want to reassign the odd_itr's next pointer to the next-next 
            // node in the list. likewise for even_itr
            if(odd_itr->next != nullptr)
            {
                odd_itr->next = odd_itr->next->next; 
            } 
            if(odd_itr->next != nullptr)
            {
                odd_itr = odd_itr->next;   
            }
            
            if(even_itr != nullptr)
            {
                if (even_itr->next != nullptr)
                {
                    even_itr->next = even_itr->next->next; 
                }
                even_itr = even_itr->next; 
            }
        }
        
        // finally, join the two lists together 
        // odd_itr will point at the end of the odd list 
        odd_itr->next = even_head_ptr->next; 
        
        // clean up
        delete even_head_ptr; 
        odd_itr = nullptr; 
        delete odd_itr; 
        even_itr = nullptr; 
        delete even_itr; 
        
        return head; 
    }
};