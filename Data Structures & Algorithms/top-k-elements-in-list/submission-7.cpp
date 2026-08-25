class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for(auto& [key, value] : count){
            pq.push({key, value});
        }

        vector<int> res;
        while(!pq.empty() && k > 0){
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
};
