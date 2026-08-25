class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map <int, int> sumMap;
        std::vector<int> ans;

        for(int i = 0; i < numbers.size(); i++){
            int diff = target - numbers[i];
            if(sumMap.find(diff) != sumMap.end()){
                ans.push_back(sumMap[diff]+1);
                ans.push_back(i+1);
                return ans;
            }
            sumMap[numbers[i]] = i;
        }
        return {-1, -1};
    }
};
