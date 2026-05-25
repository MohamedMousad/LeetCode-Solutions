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
    ListNode* addTwo(ListNode* l1, ListNode* l2 , bool add = 0){
        if (!l1 && !l2 && !add) return nullptr;
        ListNode* new_list = new ListNode((int)(add));
        if (l1) new_list->val +=l1->val;
        if (l2) new_list->val +=l2->val;
        if (new_list->val > 9) new_list->val %=10 , add = 1;
        else add = 0;
        new_list->next = addTwo((!l1 ? l1 : l1->next) , (!l2 ? l2 : l2->next) , add);
        return new_list;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwo(l1 , l2 );
    }
};