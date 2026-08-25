class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for(int& num : nums){
            ans[num-1] = num;
        }
        vector<int> res;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == 0){
                res.push_back(i + 1);
            }
        }
        return res;
    }
};