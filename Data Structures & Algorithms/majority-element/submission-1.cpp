class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int m = 0;
        int res = 0;
        for(int num : nums){
            mp[num]++;
            if(mp[num] > m){
                m = mp[num];
                res = num;
            }
        }
        return res;
    }
};