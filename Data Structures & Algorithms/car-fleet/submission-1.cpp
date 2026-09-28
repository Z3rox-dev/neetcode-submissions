class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> orderPosition;
        for(int i = 0; i < position.size(); i++){
            orderPosition.push_back(make_pair(position[i], speed[i]));
        }

        std::sort(orderPosition.begin(), orderPosition.end());

        vector<pair<double, int>> stk;

        for(int i = orderPosition.size()-1; i >= 0; i--){
            double time = double((target - orderPosition[i].first)) / orderPosition[i].second;
            if(stk.empty() || time > stk.back().first){
                stk.push_back(make_pair(time, 0));
            }
        }
        return stk.size();;
    }
};
