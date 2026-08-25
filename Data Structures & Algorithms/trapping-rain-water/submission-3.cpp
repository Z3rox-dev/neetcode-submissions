class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxLeft = height[left];
        int maxRight = height[right];
        int ans = 0;
        while(left < right){
            if(height[left] < height[right]){
                left++;
                maxLeft = std::max(maxLeft, height[left]);
                ans += maxLeft - height[left];
            }
            else{
                right--;
                maxRight = std::max(maxRight, height[right]);
                ans += maxRight - height[right];
            }
        }
        return ans;
    }
};
