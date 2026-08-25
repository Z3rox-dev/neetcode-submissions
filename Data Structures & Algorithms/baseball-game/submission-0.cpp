class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+" && !st.empty()){
                if(st.size() == 1) continue;
                int temp = st.top();
                st.pop();
                int temp2 = st.top();
                st.push(temp);
                st.push(temp + temp2);
            }
            else if(operations[i] == "D" && !st.empty()){
                int op = st.top() * 2;
                st.push(op);
            }
            else if(operations[i] == "C" && !st.empty()){
                st.pop();
            }
            else{
                int op = stoi(operations[i]);
                st.push(op);
            }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};