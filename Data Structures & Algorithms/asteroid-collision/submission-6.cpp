class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> st;
       st.push(asteroids[0]);
       for(int i = 1; i < asteroids.size(); i++){
            bool pushstack = true;
            int ast = asteroids[i];

            while(!st.empty() && pushstack && st.top() > 0 && ast < 0){
                if(abs(st.top()) < abs(ast)){
                    st.pop();
                    continue;
                }
                if(st.top() + ast == 0){
                    st.pop();
                    pushstack = false;
                    break;
                }

                pushstack = false;
            }

            if(pushstack){
                st.push(ast);
            }
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};