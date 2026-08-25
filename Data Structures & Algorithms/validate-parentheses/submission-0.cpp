class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> match = {{'(',')'}, {'[',']'}, {'{','}'}};

        for(const char& c : s){
            if(match.find(c) != match.end()){
                stack.push(c);
                continue;
            }
            else{
                if(stack.empty()){
                    return false;
                }
            }
            char top = stack.top();
            if(match[top] != c){
                return false;
            }
            stack.pop();
        }
        return stack.empty();
    }
};
