class Solution {
public:
    set<vector<int>> mySet;
    vector<vector<int>> res;
    vector<int> vec;

    void backtrack(vector<int>& nums, int index) {
        if (!mySet.count(vec)) {
            res.push_back(vec);
            mySet.insert(vec);
        }
        for (int i = index; i < nums.size(); ++i) {
            vec.push_back(nums[i]);
            backtrack(nums, i + 1);
            vec.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        backtrack(nums, 0);
        return res;
    }
};
