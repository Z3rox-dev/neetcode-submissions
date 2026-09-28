class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st1;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){

            while(!st1.empty() && st1.top().first < temperatures[i]){
                int idx = st1.top().second;
                st1.pop();
                res[idx] = i - idx;
            }

            st1.push(make_pair(temperatures[i], i));
        }
        return res;
    }
};
