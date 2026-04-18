/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        unordered_map<Node*,Node*> listMap;
        Node* itrOld = head; 

        while(itrOld!=nullptr){
            int val = itrOld->val;
            Node* node = new Node(val);
            listMap[itrOld] = node;
            itrOld = itrOld->next;
        }

        itrOld = head;
        while(itrOld!=nullptr){
            Node* node = listMap[itrOld];
            if(itrOld->next!=nullptr){
                node->next = listMap[itrOld->next];
            }
            if(itrOld->random!=nullptr){
                node->random = listMap[itrOld->random];
            }
            itrOld = itrOld->next;
        }
        return listMap[head];        
    }
};
