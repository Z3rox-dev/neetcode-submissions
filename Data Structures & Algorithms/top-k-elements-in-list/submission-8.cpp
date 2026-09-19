class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cc;
        for(int& n : nums){
            cc[n]++;
        }

        priority_queue<pair<int, int>> pq;
        
        for(auto& pair : cc){
            pq.push(make_pair(pair.second, pair.first));
        }

        vector<int> res;
        while(k > 0 && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res;
    }
};
