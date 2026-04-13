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
        ListNode* f = head;

        for(int i=0;i<n;i++){
            //if(f==nullptr) return nullptr;
            f = f->next;
        }
        if(f==nullptr){
            return head->next;
        }
        ListNode* s = head,*p;
        while(f!=nullptr){
            f  = f->next;
            p = s;
            s = s->next;

        }

        p->next = s->next;
        if(s==head) head=head->next;
        delete s;

        return head;
        
    }
};
