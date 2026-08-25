/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    set<Node*> st;
    void insert(Node* node){
        if(node == nullptr){
            return;
        }
        st.insert(node);
        insert(node->parent);
    }
    Node* anti_dfs(Node* node){
        if(node == nullptr){
            return nullptr;
        }

        if(st.find(node) != st.end()){
            return node;
        }
        return anti_dfs(node->parent);
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        insert(p);
        return anti_dfs(q);
    }
};