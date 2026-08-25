class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n <= 1) return s;

        int bestL = 0, bestR = 0; // inclusive

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) { l--; r++; }
            // now (l+1, r-1) is palindrome
            l++; r--;
            if (r - l > bestR - bestL) { bestL = l; bestR = r; }
        };

        for (int c = 0; c < n; c++) {
            expand(c, c);     // odd
            expand(c, c + 1); // even
        }

        return s.substr(bestL, bestR - bestL + 1);
    }
};
