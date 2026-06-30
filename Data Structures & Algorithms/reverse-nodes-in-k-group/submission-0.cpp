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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* start = dummy;

        while (true) {
            ListNode* node = start;
            int count = 0;
            while (count < k && node->next != nullptr) {
                node = node->next;
                count++;
            }
            if (count < k) break;         

            ListNode* end = node->next;       
            ListNode* groupHead = start->next; 
            reverseList(start, end);
            start = groupHead;                
        }
        return dummy->next;
    }

    void reverseList(ListNode* start, ListNode* end){
        ListNode* prev = end;
        ListNode* curr = start->next;
        while(curr != end){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        start->next = prev;   
    }
};
