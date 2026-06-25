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
        hash[nullptr] = nullptr;

        Node* curr = head;
        while(curr!=nullptr){
            
            if(hash.find(curr) ==hash.end()){
                hash[curr] = new Node(0);
            }
            hash[curr]->val = curr->val;

            if(hash.find(curr->next) == hash.end()){
                hash[curr->next] = new Node(0);
            }
            hash[curr]->next = hash[curr->next];

            if(hash.find(curr->random)==hash.end()){
                hash[curr->random] = new Node(0);
            }
            hash[curr]->random = hash[curr->random];

            curr = curr->next;
        }

        return hash[head];
    }
};
