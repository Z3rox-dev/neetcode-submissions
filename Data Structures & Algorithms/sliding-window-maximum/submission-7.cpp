class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::unordered_map<int, int> maxMap;
        std::vector<int> ans;
        int left = 0;
        int right = k;
        int maxValue = INT_MIN;
        for(int i = 0; i < k; i++){
            maxMap[nums[i]]++;
        }
        for(const auto& [key, value] : maxMap){
            maxValue = std::max(key, maxValue);
        }
        ans.push_back(maxValue);
        maxValue = INT_MIN;
        while(right < nums.size()){
            maxMap[nums[left]]--;
            if(maxMap[nums[left]] == 0) maxMap.erase(nums[left]);
            maxMap[nums[right]]++;
            maxValue = INT_MIN;
            for (const auto& [key, value] : maxMap) {
                maxValue = std::max(key, maxValue);
            }
            ans.push_back(maxValue);


            right++;
            left++;
        }
        return ans;
    }
};
