class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
    unordered_map<int, int> numbers;
    for (int num : nums) {
        numbers[num]++;
    }

    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        int product = 1;
        for (auto it = numbers.begin(); it != numbers.end(); ++it) {
            int times = it->second;
            if (it->first == nums[i]) times--; // escludi solo UNA occorrenza
            for (int c = 0; c < times; c++) {
                product *= it->first;
            }
        }
        ans.push_back(product);
    }
    return ans;
}

};
