class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int one = 2;
        int two = 1;
        for (int i = 3; i <= n; i++) {
            int cur = one + two;
            two = one;
            one = cur;
        }
        return one;
    }
};
