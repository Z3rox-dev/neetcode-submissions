class Solution {
public:
    //[-4,-1,-1,0,1,2]
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> ans;
        set<vector<int>> anset;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() -1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if((sum == 0)){
                    anset.insert(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        for(auto vec : anset){
            ans.push_back(vec);
        }
        return ans;
    }
};
