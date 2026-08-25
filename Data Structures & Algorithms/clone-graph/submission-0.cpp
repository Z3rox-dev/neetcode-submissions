/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copyMap;

    Node* dfs(Node* nodes){
            if(copyMap.find(nodes) != copyMap.end()){
                return copyMap[nodes];
            }

            Node* newNode = new Node(nodes->val);
            copyMap[nodes] = newNode;
        for(Node* node : nodes->neighbors){
           newNode->neighbors.push_back(dfs(node));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        dfs(node);
        return copyMap[node];
    }
};
