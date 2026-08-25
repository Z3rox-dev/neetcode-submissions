class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset;
        for(const int& num : nums){
            numset.insert(num);
        }
        int best = 0;
        for(int i = 0; i < nums.size(); i++){
            int cnt = 0;
            if(!numset.count(nums[i] - 1)){
                while(numset.count(nums[i] + cnt)){
                    cnt++;
                    best = max(best, cnt);
                }
            }
        }
        return best;
    }     
};
