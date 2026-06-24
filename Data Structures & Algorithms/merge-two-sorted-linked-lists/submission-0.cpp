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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode *result = new ListNode();
        ListNode *head = result;

        while(l1 && l2){
            ListNode *newnode = new ListNode();

            if(l1->val <= l2->val){
                newnode->val = l1->val;
                l1 = l1->next;
            }
            else{
                newnode->val = l2->val;
                l2 = l2->next;
            }
            result->next = newnode;
            result = result->next;
        }

        while(l1){
            ListNode *newnode = new ListNode();
            newnode->val = l1->val;
            l1 = l1->next;
            result->next = newnode;
            result = result->next;
        }

        while(l2){
            ListNode *newnode = new ListNode();
            newnode->val = l2->val;
            l2 = l2->next;
            result->next = newnode;
            result = result->next;
        }

        return head->next;
    }
};
