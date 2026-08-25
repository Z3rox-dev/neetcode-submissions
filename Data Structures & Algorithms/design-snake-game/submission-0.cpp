class SnakeGame {
public:
    int H, W;
    deque<pair<int,int>> body;
    unordered_set<long long> occ;
    int score = 0;
    vector<vector<int>> food;
    int foodIdx = 0;

    unordered_map<string, pair<int,int>> dir = {
        {"R",{0,1}}, {"L",{0,-1}}, {"U",{-1,0}}, {"D",{1,0}}
    };

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        W = width;
        H = height;
        this->food = food;
        body.push_back({0,0});
        occ.insert(encode(0,0));
    }

    int move(string direction) {
        auto [dr, dc] = dir[direction];
        int nr = body.front().first + dr;
        int nc = body.front().second + dc;

        if (!valid(nr, nc)) return -1;

        bool eat = (foodIdx < (int)food.size() &&
                    food[foodIdx][0] == nr &&
                    food[foodIdx][1] == nc);

        if (!eat) {
            auto [tr, tc] = body.back();
            body.pop_back();
            occ.erase(encode(tr, tc));
        }

        long long key = encode(nr, nc);
        if (occ.count(key)) return -1;

        body.push_front({nr, nc});
        occ.insert(key);

        if (eat) {
            score++;
            foodIdx++;
        }

        return score;
    }

private:
    bool valid(int r, int c) {
        return 0 <= r && r < H && 0 <= c && c < W;
    }

    long long encode(int r, int c) {
        return ((long long)r << 32) ^ (unsigned int)c;
    }
};