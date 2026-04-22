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
    int n=0;

    ListNode* merge2lists(ListNode* a, ListNode* b){
        if(a==nullptr && b==nullptr) return nullptr;
        if(a==nullptr) return b;
        if(b==nullptr) return a;
        //cout<<a->val<<"{}"<<b->val<<endl;

        ListNode* dummy = new ListNode(-1);
        ListNode* itr = dummy;
        while(a!=nullptr && b!=nullptr){
            if(a->val<b->val){
                itr->next = a;
                a = a->next;
            }
            else{
                itr->next = b;
                b = b->next;
            }
            //cout<<itr->val<<"()"<<itr->next->val<<"->";
            itr = itr->next;
        }
        if(a==nullptr) itr->next = b;
        if(b==nullptr) itr->next = a;
        itr = dummy->next;
        delete dummy;
        return itr;        
    }
    ListNode* merge(vector<ListNode*> lists, int s, int e){
       // cout<<s<<":"<<e<<endl;
        if(s==e){
            return lists[s];
        }
        int m = (s+e)/2;
        ListNode* first = merge(lists, s, m);
        ListNode* second = merge(lists,m+1,e);

        return merge2lists(first,second);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        n = lists.size();
        if(n==0) return nullptr;
        if(n==1) return lists[0];

        return merge(lists,0,n-1);
        
    }
};
