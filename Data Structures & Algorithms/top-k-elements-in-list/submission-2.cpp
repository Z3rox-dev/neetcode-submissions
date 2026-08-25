class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(int& n : nums){
            freqMap[n]++;
        }

        vector<int> res;
        priority_queue<pair<int,int>> pq;

        for(auto [key, value]: freqMap){
            pq.push({value, key});
        }

        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
