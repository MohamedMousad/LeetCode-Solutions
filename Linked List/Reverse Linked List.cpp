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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head , *next = nullptr  , *ansHead = nullptr;
        if (!curr || !curr->next) return head;
        if (curr->next) next = curr->next;
        while (curr && next){
            ListNode* temp = nullptr;
            if (curr == head)
                curr->next = nullptr;
            if (next->next)
                temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
            if (curr != nullptr)
                ansHead = curr;
        }
        return ansHead;
    }
};