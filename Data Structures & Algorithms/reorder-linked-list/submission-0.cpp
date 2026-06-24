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
    void reorderList(ListNode* head) {
        stack<ListNode*> stc;

        ListNode* temp = head;
        int size = 0;
        while(temp!=nullptr){
            stc.push(temp);
            temp = temp->next;
            size++;
        }
        int half = size/2;

        ListNode* curr = head;
        for(int i = 0;i<half;i++){
            ListNode *top = stc.top(); 
            stc.pop(); 
            ListNode *temp2 = curr->next; 
            curr->next = top; 
            top->next = temp2; 
            curr = temp2; 
        }

        curr->next = nullptr;
    }
};
