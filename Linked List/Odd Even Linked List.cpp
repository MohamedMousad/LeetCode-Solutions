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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* next1 = head->next;
        ListNode* curr = head , *prev = curr, *next = head->next;
        while (curr){
            if (curr && curr->next){
                curr->next = curr->next->next;
                if (curr) prev = (curr->next ? curr->next : curr);
                curr = curr->next;
            }
            else 
                break;
            if (next && next->next)
                next->next = next->next->next , next = next->next;
        }
        prev->next = next1;
        return head;
    }
};