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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto curr = head; int sz = 0 ; auto curr2 = head;
        while(curr2){
            curr2 = curr2->next;
            sz++;
        }
        if (sz - n == 0) {
            auto temp = curr->next;
            curr->next = nullptr;
            return temp;
        }
        int cnt=  1;
        while (curr->next){
            if(sz == n+cnt) curr->next = curr->next->next ;
            else curr = curr->next;
            cnt++;
        }
        return head;
    }
};