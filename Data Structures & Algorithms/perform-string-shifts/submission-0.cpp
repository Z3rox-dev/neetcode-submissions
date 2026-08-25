class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.size();
        int total = 0;

        for (auto& op : shift) {
            int dir = op[0];
            int amount = op[1];

            if (dir == 0) total -= amount; // left
            else total += amount;          // right
        }

        total %= n;
        if (total < 0) total += n;

        return s.substr(n - total) + s.substr(0, n - total);
    }
};