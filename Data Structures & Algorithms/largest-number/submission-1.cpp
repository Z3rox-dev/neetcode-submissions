class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(), nums.end(), [&](int& a, int& b){
            string sa = to_string(a);
            string sb = to_string(b);
            return sa + sb > sb + sa;
        });
        if(nums[0] == 0) return "0";
        for(auto& num : nums){
            res += to_string(num);
        }
        return res;
    }
};