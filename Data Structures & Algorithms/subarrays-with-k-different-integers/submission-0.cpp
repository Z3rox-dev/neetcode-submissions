class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> sub;
        int left = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            sub.clear();
            for(int j = i; j < nums.size(); j++){
                sub[nums[j]]++;
                if(sub.size() == k){
                res++;
                }
            }

        }
        return res;
    }
};