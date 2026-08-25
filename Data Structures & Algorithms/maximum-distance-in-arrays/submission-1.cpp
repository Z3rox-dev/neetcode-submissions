class Solution {
public:
    struct minCmp {
        bool operator()(const auto& a, const auto& b){
            return a.second > b.second;
        }
    };

    struct maxCmp {
        bool operator()(const auto& a, const auto& b){
            return a.second < b.second;
        }
    };

    int maxDistance(vector<vector<int>>& arrays) {
        int min = INT_MAX;
        int max = 0;

        priority_queue<pair<int, int> , vector<pair<int, int>>, maxCmp> maxHeap;
        priority_queue<pair<int, int> , vector<pair<int, int>>, minCmp> minHeap;

        for(int i = 0; i < arrays.size(); i++){
            minHeap.push({i, arrays[i][0]});
            maxHeap.push({i, arrays[i].back()});
        }

        if(minHeap.top().first != maxHeap.top().first){
            return abs(minHeap.top().second - maxHeap.top().second);
        }

        int minTop = minHeap.top().second;
        int maxTop = maxHeap.top().second;

        minHeap.pop(); maxHeap.pop();

        int ans = 0;
        ans = std::max(ans, maxTop - minHeap.top().second);
        ans = std::max(ans, maxHeap.top().second - minTop);

        return ans;
    }
};
