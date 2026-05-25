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
    int pairSum(ListNode* head) {
        vector<int> a;
        while (head){
            a.push_back(head->val);
            head = head->next;
        }
        int ans = 0;
        for (int l  = 0 , r = a.size() - 1 ; l < r ; r-- , l++)
            ans = max(ans , a[r] + a[l]);
        return ans;
    }
};