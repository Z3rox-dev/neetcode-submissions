class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset;
        for(const int& num : nums){
            numset.insert(num);
        }
        int best = 0;
        for(const int& num : numset){
            int cnt = 0;
            if(!numset.count(num - 1)){
                while(numset.count(num + cnt)){
                    cnt++;
                }
                best = max(best, cnt);
            }
        }
        return best;
    }     
};
