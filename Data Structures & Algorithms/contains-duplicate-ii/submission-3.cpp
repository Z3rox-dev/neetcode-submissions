class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int currentmax = 0;
        for(int num : nums){
            currentmax = max(currentmax, num);
        }
        vector<int> indices(currentmax + 1, -1);

        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
            if(indices[nums[i]] == -1 || count[nums[i]] > 2) {
                indices[nums[i]] = i;
            }
            if(count[nums[i]] > 1 && indices[nums[i]] != -1){
                if(abs(indices[nums[i]] - i) <= k){
                    return true;
                }
            }
        }
        return false;
    }
};