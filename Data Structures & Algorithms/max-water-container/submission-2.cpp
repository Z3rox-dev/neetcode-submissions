class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int max = 0;
        while(left < right){
            int cur = min(heights[right], heights[left]) * (right - left);
            max = std::max(max, cur);
            if(heights[right] > heights[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return max;
    }
};
