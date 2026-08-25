class Solution {
public:
    int maxArea(vector<int>& heights) {
        int j = heights.size()-1;
        int i = 0;
        int maxArea = 0;
        while(i < j){
        int currentArea = std::min(heights[i], heights[j]) * (j - i);
        maxArea = std::max(maxArea, currentArea);
            if(heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
    return maxArea;
    }
};
