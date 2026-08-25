class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map <int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first < b.first;
        };

        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            decltype(cmp)
        > queue(cmp);
        
        for(const auto& [key, value] : freq){
            queue.push({value, key});
        }
        std::vector<int> ans;
        while(k > 0){
            ans.push_back(queue.top().second);
            queue.pop();
            k--;
        }
        return ans;
    }
};
