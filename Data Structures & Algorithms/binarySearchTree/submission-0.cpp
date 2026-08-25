struct TreeNode{
    int val;
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, int key) : val(val), key(key), left(nullptr), right(nullptr) {}

};

class TreeMap {

public:
    TreeNode* tree;
    TreeMap() : tree(nullptr){}

    
    void insert(int key, int val) {
        if(tree == nullptr){
            tree = new TreeNode(val, key);
            return;
        }

        TreeNode* curr = tree;
        while(true){
            if(key < curr->key){
                if(!curr->left){
                    curr->left = new TreeNode(val, key);
                    return;
                }
                curr = curr->left;
            }

            else if(key > curr->key){
                if(!curr->right){
                    curr->right = new TreeNode(val, key);
                    return;
                }
                curr = curr->right;
            }
            else{
                curr->val = val;
                return;
            }
        }
    }

    int get(int key) {
        if(tree == nullptr) return -1;
        TreeNode* curr = tree;
        while(curr != nullptr){
            if(key < curr->key){
                curr = curr->left;
            }
            else if(key > curr->key){
                curr = curr->right;
            }
            else if (key == curr->key){
                return curr->val;
            }
        }
        return -1;
    }

    int getMin() {
        if(tree == nullptr) return -1;

        TreeNode* curr = tree;
        while(curr->left != nullptr){
            curr = curr->left;
        }
        return curr->val;
    }

    int getMax() {
        if(tree == nullptr) return -1;

        TreeNode* curr = tree;
        while(curr->right != nullptr){
            curr = curr->right;
        }
        return curr->val;
    }
    TreeNode* removeRecursive(TreeNode* root, int key){
        if(root == nullptr) return nullptr;
        if(key < root->key){
            root->left = removeRecursive(root->left, key);
        }
        else if(key > root->key){
            root->right = removeRecursive(root->right, key);
        }
        else{
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* curr = root->right;
            while(curr->left) curr = curr->left;

            root->key = curr->key;
            root->val = curr->val;
            root->right = removeRecursive(root->right, curr->key);
        }
        return root;
    }

    void remove(int key) {
        if(tree == nullptr) return;
        tree = removeRecursive(tree, key);
    }

    std::vector<int> getInorderKeys() {
        if(tree == nullptr) return {};

        vector<int> temp;
        TreeNode* curr = tree;
        stack<TreeNode*> s;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            curr =  s.top();
            s.pop();
            temp.push_back(curr->key);
            curr = curr->right;
        }
        return temp;
    }
};
