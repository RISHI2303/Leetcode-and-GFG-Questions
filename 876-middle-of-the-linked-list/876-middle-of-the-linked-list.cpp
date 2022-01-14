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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        ListNode *p = head;
        int len=0;
        
        while(p) {
            len++;
            p = p->next;
        }
        
        p = head;
        for(int i=0; i<(len/2); i++) {
            p = p->next;
        }
        return p;
    }
};