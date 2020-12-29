/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* ATTEMPT #1 */  

/**
* P: going to try some math to see if I can proof my way into a solution. BRB. 
* Nope, didn't work. Here's my inefficient idea: 
* - if head == nullptr, return null 
* - create pointer itr = head
* - create vector of ListNode* seen
* - iterate through list: while (itr != nullptr)
*   - if itr is in seen: return itr 
*   - (else) add itr to seen
*   - itr = itr -> next 
* - (itr == nullptr) return null 
* 
*/

/** I: 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // case: 0 nodes in list 
        if (head == nullptr)
        {
            return nullptr; 
        }
        
        // if there's nodes in the list, iterate through the entire list, keeping 
        // track of nodes we've already seen 
        ListNode* itr = head; 
        unordered_map<ListNode*, bool> seen; 
        while (itr != nullptr)
        {
            // if we've already seen this node, we're in a cycle. return this node 
            
            if (seen[itr] == true)
            {
                return itr; 
            }
            
            // we haven't seen this node yet, so add it to the list 
            seen[itr] = true;  
            itr = itr->next; 
        }
        
        // if we get here, the list ended, so no cycle. return null
        return nullptr; 
    }
};
*/ 

// R: ran through test cases on my own 

/**
* E: 
* - Runtime: O(N) 
* - Space: O(N)
* - Improvement: Could have used two pointers to implement Floyd's algorithm for cycle detection,
*    then used math to figure out which index was the start of the cycle for O(1) space use. 
*    This would result in a longer runtime, but it would still come out to O(N) in the end. 
*/

/* ATTEMPT #2 */ 

/**
* U: 
*   head = [3, 2, 0, -4, 5], pos = 2
*   head = [1, 2], pos = 0 
*   head = [1], pos = -1 (no cycle)
*   head = nullptr 
*/

/**
* M: linked list yes, two pointer maybe, dummy head no, pointer bookkeeping maybe, multi-pass no 
*/

/**
* P: Based on Floyd's algorithm for cycle detection. 
*   Let there be two pointers, a tortoise and a hare. Every time the tortoise moves one node             *       forward, the hare moves two nodes forward. If the hare's next or next-next pointer 
*       is null, then there is no cycle. Else, if the tortoise and the hare ever point at 
*       the same node, there is a cycle. 
*   Let the distance between the node where the list starts and the node where the cycle starts
*       be p. 
*   Let the distance between the node where the cycle starts and the node where the tortoise and
*       the hare meet be q. 
*   Let c be the length of the cycle, and let k be some integer representing a number of loops 
*       taken around the cycle. 
*   When the tortoise and the hare meet, the tortoise has traveled a total of p + q nodes from 
*       the start. 
*   Because the hare traveled twice as fast as the hare, the hare must have traveled 2(p+q) nodes. 
*   But the hare also made some number of loops around the cycle, and because it ended up on the 
*       same node that the tortoise is on, the hare must have traveled kc + (p + q) nodes away 
*       from the start. 
*   Then we can show that p = kc - q (i.e. that the distance from the start of the list to the start
*       of the cycle is equal to the distance from where the tortoise and hare met forward to the 
*       node where the cycle begins again) like so: 
*       2(p + q) = kc + p + q
*       2p + 2q = kc + p + q 
*       p + q = kc 
*       p = kc - q
*   So, since the distance from the start of the list to the start of the cycle is the same as the 
*       distance from where the tortoise and the hare currently are forward to the start of the cycle, 
*       we move the tortoise pointer back to the head of the list. Then, walk the tortoise and the hare 
*       forward one node at a time each until they meet again. The node where they meet must be where
*       the cycle started. Return this node. 
*/ 

// I: 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // case: 0 nodes in list 
        if (head == nullptr)
        {
            return nullptr; 
        }
        
        // if there's nodes in the list, create a tortoise and hare pointer. the tortoise will 
        // walk forward one node at a time; the hare will walk forward two nodes for each node 
        // the tortoise walks through 
        ListNode* tortoise = head; 
        ListNode* hare = head; 
        
        // if the hare ever finds a nullptr ahead of it, we know the list ends and there is 
        // no cycle 
        while (hare->next != nullptr && hare->next->next != nullptr)
        {
            // move the tortoise and the hare forward 
            tortoise = tortoise->next; 
            hare = hare->next->next; 
            
            // do the tortoise and the hare point at the same node yet?
            if(tortoise == hare)
            {
                // if so, then move the tortoise back to the head
                tortoise = head; 
                
                // then move each pointer forward at the same speed until they meet. the 
                // node where they meet is where the cycle starts
                while(tortoise != hare)
                {
                    tortoise = tortoise->next; 
                    hare = hare->next; 
                }
                return tortoise; 
            }
        }
        return nullptr; 
    }
};

/** 
* R: kind of glossed over this because I spent so much time working on the math to prove it worked
* for any cyclic case, oops
*/ 

/**
* E: runtime O(N), space O(1)
* Could be improved using other known algorithms for cycle detection-- I know of one that purely uses
* math to determine on which period the tortoise and hare meet without having to cycle through the list
* multiple times as Floyd's algorithm does, but I haven't tried implementing it yet. 
*/

