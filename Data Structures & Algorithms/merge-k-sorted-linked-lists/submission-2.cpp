/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 145
 134
 26
 */

class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1; 
        }
        else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    ListNode* divide(vector<ListNode*> &lists, int left, int right){
        if(left == right) return lists[left];
        int mid = left + (right-left)/2;

        ListNode* l1 = divide(lists, left, mid);
        ListNode* l2 = divide(lists, mid+1, right);

        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        return divide(lists, 0, n-1);
    }
};
