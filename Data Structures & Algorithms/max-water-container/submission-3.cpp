class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int max = 0;

        while(left < right){
            int minHeight = std::min(heights[left], heights[right]);
            int width = right - left;
            max = std::max(max, minHeight * width);

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
