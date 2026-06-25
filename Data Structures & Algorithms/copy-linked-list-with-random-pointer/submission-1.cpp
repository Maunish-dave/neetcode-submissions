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

    unordered_map<Node*,Node*> hash;
    Node* copyRandomList(Node* head) {
        if (head ==nullptr) return head;
        if (hash.count(head)) return hash[head];

        Node* copy = new Node(head->val);
        hash[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = hash[head->random];
        return copy;
    }

};


