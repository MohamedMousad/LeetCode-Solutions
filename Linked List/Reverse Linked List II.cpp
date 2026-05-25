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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode *curr = head , *l = nullptr , *prev_l = nullptr , *prev = nullptr; 
        int cnt = 1;
        while (curr){
            if (cnt == left - 1) prev_l = curr;
            if (cnt == left) l = curr;
            ListNode *nxt = curr->next;
            if (cnt > left && cnt <= right ){
                curr->next = prev;
                if (cnt == right) {
                    if (prev_l)
                        prev_l->next = curr;
                    l->next = nxt;
                    
                    return left == 1 ? curr : head;
                }
            }
            prev = curr;
            curr = nxt;
            cnt++;
        }
        return head;
    }
};