class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = (int)picture.size();
        int n = (int)picture[0].size();

        vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (picture[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }

        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1)
                    res++;

        return res;
    }
};
