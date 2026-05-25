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
        sort(nums.begin() , nums.end());
        auto curr = head;
        while (curr){
            auto next = curr->next;
            if (!next) break;
            auto it  = lower_bound(nums.begin() , nums.end() ,  next->val);
            while (next && it != nums.end() && *it == next->val){
                next = next->next;
                if (next)
                    it  = lower_bound(nums.begin() , nums.end() ,  next->val);
            }
            curr->next = next;
            curr = curr->next;
        }
        auto it  = lower_bound(nums.begin() , nums.end() ,  head->val);
        if ( it != nums.end() && *it == head->val)
            head = head->next;
        return head ;
    }
};