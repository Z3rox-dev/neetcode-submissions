class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(int& n : nums){
            freqMap[n]++;
        }

        vector<int> res{};
        vector<vector<int>> bucket(nums.size() + 1, vector<int>());
        for(auto [key, value] : freqMap){
            bucket[value].push_back(key);
        }

        for(int i = bucket.size() - 1; i > 0; i--){
            for(int j = 0; j < bucket[i].size(); j++){
                res.push_back(bucket[i][j]);
                if(res.size() == k){
                    return res;
                }
            }
        }

        return res;
    }
};
