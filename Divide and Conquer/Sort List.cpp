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
    ListNode* merge(ListNode* first, ListNode* second){
        if (!first)
            return second;
        if (!second)
            return first;
        ListNode* curr1 = first, *curr2 = second , *ans = nullptr , *res = nullptr;
        while (curr1 || curr2){
            ListNode* nxt = nullptr;
            bool flag = false;
            if (curr1 && curr2 && curr1->val <= curr2->val)
                nxt = curr1 , curr1 = curr1->next;
            else if(curr1 && curr2 && curr1->val > curr2->val)
                nxt = curr2 , curr2 = curr2->next;
            else {
                flag = true;
                if (curr1) nxt = curr1;
                else nxt = curr2;
            }
            if (!ans) {
                res = ans = nxt;
                continue;
            }
            else ans->next = nxt;
            if (flag) break;
            ans = ans->next;
        }
        return res;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        ListNode* ans = nullptr;
        queue<ListNode*> q;
        auto *curr = head;
        while (curr){
            auto * temp = curr->next;
            curr->next = nullptr;
            q.push(curr);
            curr = temp;
        }
        while (q.size() >= 2 ){
            auto *first = q.front();
            q.pop();
            auto *second = q.front();
            q.pop();
            q.push(merge(first , second));
        }
        return q.empty() ? nullptr : q.front();   
    }
};