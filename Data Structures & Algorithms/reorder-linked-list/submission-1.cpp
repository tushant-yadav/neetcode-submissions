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

    ListNode* reverse(ListNode* head){
        ListNode* p = nullptr, *c=head, *n;
        while(c!=nullptr){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
    void reorderList(ListNode* head) {

        ListNode* f = head, *s = head;

        while(f && f->next){
            f = f->next->next;
            s = s->next;
        }

        ListNode* head2 = reverse(s->next);
        s->next = nullptr;
        s = head;
        // 1 .2 3 4 5
        // /9 .8 7 6
        ListNode* itr = head;
        while(head && head2){
            head = head->next;
            itr->next = head2;
            head2 = head2->next;
            itr=itr->next;
            itr->next = head;
            itr = itr->next;
        }
        //return s;
    }
};
