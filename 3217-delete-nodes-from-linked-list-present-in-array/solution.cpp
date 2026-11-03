// 111 ms | 263.2 MB
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
        
        unordered_set<int> st(nums.begin(), nums.end());

        ListNode dummy(0, head);
        ListNode* pre = &dummy;
        ListNode* curr = head;

        while(curr != NULL) {
            if(st.count(curr->val)) {
                pre->next = curr->next;
                curr = pre->next;
            }
            else {
                pre = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};