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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* one = head;
        ListNode* two = head;
        while(n--) {
            two = two->next;
        }
        if(two == NULL) // length of ll = n then delete first node
            return one->next;
        
        while(two->next != NULL) {
            one = one->next;
            two = two->next;
        }
        //delete nth index
        one->next = one->next->next; // memory leak
        
        return head;
    }
};