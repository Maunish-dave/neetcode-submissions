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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode *prev = dummy;

        while(n--){
            curr = curr->next;
        }

        while(curr){
            prev = prev->next;
            curr = curr->next;
        }

        
        prev->next = prev->next->next;
        return dummy->next;
    }
};
