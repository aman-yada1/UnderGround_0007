// 0 ms | 14.7 MB
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
    int count(ListNode* head){
        ListNode* temp = head;
        int n = 0;

        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = count(head) - n;

        ListNode* curr = head;
        ListNode* pre = NULL;

        if(k == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while( k > 0){
            pre = curr;
            curr = curr->next;
            k--;
        }
        pre->next = curr->next;
        delete curr;

        return head;
    }
};