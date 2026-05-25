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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode* curr = list1 , *curr2 = list2 , *tmp = nullptr , *head = nullptr;
        while (curr && curr2){
            if (curr->val <= curr2->val){
                if (!head) head = curr;
                while (curr->next && curr->next->val <= curr2->val)
                    curr = curr->next;
                tmp = curr->next;
                curr->next = curr2;
                curr = curr->next;
                curr2 = tmp;
            }
            else {
                if (!head) head = curr2;
                while (curr2->next && curr2->next->val <= curr->val)
                    curr2 = curr2->next;
                tmp = curr2->next;
                curr2->next = curr;
                curr2 = curr2->next;
                curr = tmp;
            }
        }
        return head;
    }
};