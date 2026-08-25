class Leaderboard {
public:
    list<pair<int,int>> ll; // (playerId, currentScore)
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    priority_queue<pair<int,int>> pq; // (scoreSnapshot, playerId)

    Leaderboard() {}

    void addScore(int playerId, int score) {
        auto it = mp.find(playerId);
        if (it == mp.end()) {
            ll.push_back({playerId, score});
            auto lit = prev(ll.end());
            mp[playerId] = lit;
            pq.push({score, playerId});
        } else {
            it->second->second += score;
            pq.push({it->second->second, playerId});
        }
    }

    int top(int K) {
        int sum = 0;
        vector<pair<int,int>> keep;
        keep.reserve(K);

        while (K > 0) {
            while (!pq.empty()) {
                auto [snapScore, id] = pq.top();

                auto it = mp.find(id);
                if (it == mp.end()) {
                    pq.pop();
                    continue;
                }

                int curScore = it->second->second;
                if (curScore != snapScore) {
                    pq.pop();
                    continue;
                }
                break;
            }

            if (pq.empty()) break;

            auto p = pq.top(); pq.pop();
            sum += p.first;
            keep.push_back(p);
            K--;
        }

        for (auto &p : keep) pq.push(p);
        return sum;
    }

    void reset(int playerId) {
        auto it = mp.find(playerId);
        if (it == mp.end()) return;
        ll.erase(it->second);
        mp.erase(it);
    }
};