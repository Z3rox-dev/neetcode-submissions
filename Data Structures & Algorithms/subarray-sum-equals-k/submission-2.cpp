class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currentSum = 0;
        int res = 0;
        
        unordered_map<int, int> prefixCheat = {{0, 1}};

        for(int i = 0; i < nums.size(); i++){
            currentSum += nums[i];
            auto it = prefixCheat.find(currentSum - k);
            if(it != prefixCheat.end()){
                res += it->second;
            }
            prefixCheat[currentSum]++;
        }

        return res;
    }
};