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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        while (head != nullptr && valuesToRemove.count(head->val) > 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == nullptr) {
            return nullptr;
        }

        ListNode* current = head;
        while (current->next != nullptr) {
            if (valuesToRemove.contains(current->next->val)) {
                // Store the node to be deleted
                ListNode* temp = current->next;
                // Skip the next node by updating the pointer
                current->next = current->next->next;
                // Delete the removed node
                delete temp;
            } else {
                // Move to the next node
                current = current->next;
            }
        }

        return head;
    }
};