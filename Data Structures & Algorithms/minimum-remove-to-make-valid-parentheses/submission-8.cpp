class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::deque<char> openParentheses;
        std::string answer;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c == '('){
                openParentheses.push_front(c);
            }
            if(c == ')'){
                if(openParentheses.empty()) continue;
                else openParentheses.pop_front();
            }
            answer += c;
        }
        if(answer.length() == 0) return "";
        std::string answer2;
        openParentheses.clear();
            for(int i = answer.length()-1; i >= 0; i--){
            char c = answer[i];
            if(c == ')'){
                openParentheses.push_front(c);
            }
            if(c == '('){
                if(openParentheses.empty()) continue;
                else openParentheses.pop_front();
            }
            answer2 += c;
        }
        std::reverse(answer2.begin(), answer2.end());
        return answer2;
    }
};
