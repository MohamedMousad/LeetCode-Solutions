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
        auto curr = head;
        int freq[210] = {};
        while (curr){
            freq[curr->val + 100]++;
            curr = curr->next;
        }
        curr = head ;
        auto last = head;
        bool flag = false;
        for (int i = 0 ; i < 210 ; i++){
            if (freq[i] == 1){
                curr->val = i-100;
                last = curr;
                flag = true;
                curr = curr->next;
            }
        }
        if (last)
        last->next = nullptr;
        return (flag == true ? head : nullptr);
    }
};