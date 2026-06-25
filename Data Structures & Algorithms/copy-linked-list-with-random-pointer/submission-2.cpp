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
        unordered_map<Node*,Node*> hash;

        // create copies of all the node
        Node* curr = head;
        while(curr!=nullptr){
            Node* copy = new Node(curr->val);
            hash[curr] = copy;
            curr = curr->next;
        }

        // create the new list
        curr = head;
        while(curr!=nullptr){
            Node* copy = hash[curr];
            copy->next = hash[curr->next];
            copy->random = hash[curr->random];
            curr = curr->next;
        }

        return hash[head];
        
    }
};
