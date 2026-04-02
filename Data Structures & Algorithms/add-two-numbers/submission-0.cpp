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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* itr1 = l1, *itr2 = l2;
        ListNode* last=nullptr, *ret=l1;
        int sum = 0, carry = 0;
        while(itr1 && itr2) {
            sum = itr1->val + itr2->val + carry;
            carry = sum/10;
            sum = sum%10;
            itr1->val = sum;
            last = itr1;
            itr1 = itr1->next; itr2 = itr2->next;
            }

        if(itr2!=nullptr){
            last->next = itr2;
            itr1 = itr2;
        }

        while(carry!=0 && itr1!=nullptr){
            sum = itr1->val + carry;
            carry = sum/10;
            sum = sum%10;
            itr1->val = sum; 
            last = itr1;
            itr1 = itr1->next;            
        }

        if(carry!=0){
            last->next = new ListNode(carry);
        }
        return ret;
    }
};
