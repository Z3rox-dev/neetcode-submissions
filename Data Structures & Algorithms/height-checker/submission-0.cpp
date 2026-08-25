class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h = heights;
        sort(h.begin(), h.end());
        int cnt = 0;
        for(int i = 0; i < heights.size(); i++){
            if(h[i] != heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};