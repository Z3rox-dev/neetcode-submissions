class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        priority_queue<int> pq;
        unordered_set<int> mp;

        for(auto& num : nums){
            if(mp.count(num)) continue;

            mp.insert(num);
            pq.push(num);
        }

        int n = pq.top();
        pq.pop();
        int cur = 1;
        int best = 1;
        while(!pq.empty()){
            int next = pq.top();
            if(n - pq.top() == 1){
                cur +=1;
                best = max(cur, best);
                pq.pop();
            }
            else{
                cur = 1;
                pq.pop();
            }
            n = next;
        }
        return best;
    }
};
