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
    int getDecimalValue(ListNode* head) {
        stack<int> st;
        int ans = 0 , mul = 1;
        while (head){
            st.push(head->val);
            head= head->next;
        }
        while (!st.empty()){
            ans += (st.top()*mul);
            st.pop();
            mul<<=1;
        }
        return ans;
    }
};