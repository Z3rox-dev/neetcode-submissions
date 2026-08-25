class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxArea = 0;
        while(left < right){
            int minimum = min(heights[right], heights[left]);
            int area = (right - left) * minimum;
            maxArea = max(maxArea, area);
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};
