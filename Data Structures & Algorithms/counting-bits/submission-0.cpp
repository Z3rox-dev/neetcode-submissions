class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        if(n == 0){
            res.push_back(0);
            return res;
        }

        auto cnt = [](int y){
            int ans = 0;
            while(y > 0){
                ans += (y & 1);
                y >>= 1;
            }
            return ans;
        };

        int x = 0;
        while(x <= n){
            res.push_back(cnt(x));
            x++;
        }

        return res;
    }
};
