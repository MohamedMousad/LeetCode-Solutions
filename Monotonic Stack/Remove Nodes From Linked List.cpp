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
    ListNode* removeNodes(ListNode* head) {
        vector<long long> a, suffix;
        long long maximum = 0 , counter = 0;
        auto first = head;
        for (auto i = head; i != NULL; i = i->next) {
            a.push_back(i->val);
        }
        suffix.resize(a.size());
        for (long long i = a.size() - 1; i >= 0; i--) {
            if (a[i] >= maximum) {
                suffix[i] = 1;
            } else {
                suffix[i] = 0;
            }
            maximum = max(maximum, a[i]);
        }
        for (long long i = 0; i < suffix.size(); i++) {
            if (suffix[i] == 1) {
                counter++;
                head->val = a[i];
                if (i!= suffix.size() - 1 )
                {
                    head->next = new ListNode();
                    head = head->next;
                }
            }
        }
        if (counter == 1)
        {
            head->next =  new ListNode();
            head->next = NULL;
            delete head->next;
        }
        return first;
    };
};