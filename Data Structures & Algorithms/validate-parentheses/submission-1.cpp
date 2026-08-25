class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char, char> valids = {
            {')', '('},
            {']', '['},
            {'}', '{'}
            };

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                open.push(c);
            }
            else if(open.empty()){
                return false;
                }
            else  {
                char opened = open.top();
                open.pop();
                if(opened != valids[c]){
                    return false;
                }
            }
        }
        return open.empty();
    }
};
