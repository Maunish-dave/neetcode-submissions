/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == nullptr){
            return nullptr;
        }

        // created interleaved linked list
        Node* l1 = head;
        while(l1 != nullptr){
            Node* l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
        }

        // now assign random next
        Node* newHead = head->next;

        l1 = head;
        while(l1!=nullptr){
            if(l1->random != nullptr){
                l1->next->random = l1->random->next; // A`.random = A`.random.next; (copied random)
            }
            l1 = l1->next->next;
        }

        l1 = head;
        while(l1 != nullptr){
            Node* l2 = l1->next;
            l1->next = l2->next;
            if(l1->next !=nullptr){
                l2->next = l2->next->next;
            }
            l1 = l1->next;
        }

        return newHead;
    }
};
