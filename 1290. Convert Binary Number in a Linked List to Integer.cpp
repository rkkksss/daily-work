/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        long long ans = 0;
        while (head) {
            int a = head->val;
            ans *= 2;
            ans += a;
            head = head->next;
        }
        return ans;
    }
};
