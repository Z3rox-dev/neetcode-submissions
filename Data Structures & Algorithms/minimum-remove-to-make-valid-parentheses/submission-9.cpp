class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string res = "";
        for(char& c : s){
            if(c == '('){
                st.push(c);
                res += c;
            }
            else if(c == ')'){
                if(!st.empty()){
                    st.pop();
                    res += c;
                }
            }
            else{
                res += c;
            }
        }
        st = stack<char>();
        reverse(res.begin(), res.end());
        string temp = res;
        res = "";
        for(char& c : temp){
            if(c == ')'){
                st.push(c);
                res += c;
            }
            else if(c == '('){
                if(!st.empty()){
                    st.pop();
                    res +=c;
                }
            }
            else{
                res += c;
            }
        }
        reverse(res.begin(), res.end());
        string ans = res;
        return ans;
    }
};
