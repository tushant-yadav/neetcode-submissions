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
/*


*/
class Solution {
public:
    ListNode* reversell(ListNode* head){
        ListNode* c=head,*n,*p=NULL;
        while(c!=NULL){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head, *slow= head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // Step 2: Reverse the second half
        ListNode* second = reversell(slow->next);
        slow->next = NULL; // Break the list into two halves

        // Step 3: Merge the two halves
        ListNode* first = head;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
        //return head;
    
};
