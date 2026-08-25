class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int distance;

    std::priority_queue< std::pair<int, std::pair<int, int>>, 
                        std::vector<std::pair<int, std::pair<int, int>>>, 
                        std::greater<> > pq;

        for(int i = 0; i < points.size(); i++){
            distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({distance, {points[i][0], points[i][1]}});
        }
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < k; i++) {
            auto [x, y] = pq.top().second;
            ans.push_back({x, y});
            pq.pop();
        }
        return ans;
    }
};
