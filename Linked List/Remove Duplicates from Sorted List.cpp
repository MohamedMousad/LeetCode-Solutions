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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        auto curr = head , curr2 = head->next;
        while (curr2){
            if (curr2->val != curr->val)
                curr->next = curr2 , curr = curr->next;
            else if (curr2->val == curr->val && !curr2->next)
                curr->next = nullptr;
            curr2 = curr2->next;
        }
        return head;
    }
};