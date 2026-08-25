class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        vector<vector<int>> res;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int n = intervals.size();
        int i = 0;

        while(i < n && newStart > intervals[i][1]){
            res.push_back(intervals[i]);
            i++;
        }

        while(i < n && intervals[i][0] <= newEnd){
            newStart = min(newStart, intervals[i][0]);
            newEnd   = max(newEnd,   intervals[i][1]);
            i++;
        }
        res.push_back({newStart, newEnd});

        while(i < n){
        res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
