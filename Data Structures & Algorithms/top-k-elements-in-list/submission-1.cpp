class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        for(const auto& num : nums){
            freq[num]++;
        } 

        priority_queue<pair<int, int>> pq;

        for(const auto [key,value] : freq){
            pq.push(make_pair(value, key));
        }

        while(!pq.empty() && k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
