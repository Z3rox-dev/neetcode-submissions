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
        if(head == nullptr) return nullptr;

        unordered_map<Node*, Node*> nextCopy;
        Node* current = head;
        while(current != nullptr){
            nextCopy[current] = new Node(current->val);
            current = current->next;
        }

        current = head;
        Node* newList = nextCopy[head];
        Node* temp = newList;
        while(current != nullptr){
            temp->next = nextCopy[current->next];
            temp->random = nextCopy[current->random];
            current = current->next;
            temp = temp->next;
        }
        return newList;
    }
};
