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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head , *prev = head ;
        curr = curr->next;
        while (curr){
            if (curr->val < prev->val){
                ListNode* temp = head ;
                prev->next = curr->next;
                if (curr->val < head->val)
                    curr->next = head , head = curr;
                else {
                    while (curr->val > temp->next->val)
                        temp = temp->next;
                    ListNode* next = temp->next;
                    temp->next = curr;
                    curr->next = next;
                }
                curr = prev;
            }
            else {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};