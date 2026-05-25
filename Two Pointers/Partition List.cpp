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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head_less = nullptr , *head_more = nullptr, *curr = head , *last_less = nullptr, *last_more = nullptr;
        if (!head) return head;
        while (curr){
            if (curr->val < x){
                if (!head_less)
                    head_less = curr;
                if (last_less)
                    last_less->next = curr;
                last_less = curr;
            }
            else {
                if (!head_more)
                    head_more = curr;
                if (last_more)
                    last_more->next = curr;
                last_more = curr;
            }
            curr = curr->next;
        }
        if (!head_less)
            return head_more;
        if (last_more) 
            last_more->next = nullptr;
        last_less->next = head_more;
        return head_less;
    }
};