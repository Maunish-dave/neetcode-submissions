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

    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val; // min heap 
        }
    };

    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        for(int i =0;i<k;i++){
            ListNode* node = lists[i];
            pq.push(node);
        }    

        // create dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();

            curr->next = smallest;
            curr = smallest;

            smallest = smallest->next;
            if(smallest) pq.push(smallest);
        }

        return dummy->next;
    }
};
