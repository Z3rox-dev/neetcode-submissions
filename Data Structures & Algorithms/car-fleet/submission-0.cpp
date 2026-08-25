class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> pairs;
        for(int i = 0; i < position.size(); i++) {
            pairs.emplace_back(position[i], speed[i]);
        }

        std::sort(pairs.rbegin(), pairs.rend());

        std::stack<double> time;
        for (const auto& [pos, spd] : pairs) {
            double timeToArrive = static_cast<double>(target - pos) / spd;
            if (!time.empty() && timeToArrive <= time.top()) {
                continue;
            }
            time.push(timeToArrive);
        }
        return time.size();
    }
};
