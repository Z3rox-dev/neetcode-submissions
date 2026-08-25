class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> target_map;
        
        for(int i = 0; i < nums.size(); i++){
            target_map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            auto it = target_map.find(need);

            if(it != target_map.end() && i != it->second){
                return {i, it->second};
            }
        }
        return {};
    }
};
