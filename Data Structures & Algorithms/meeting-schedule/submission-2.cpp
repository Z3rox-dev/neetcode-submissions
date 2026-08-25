/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>> intVal;
        for(int i = 0; i < intervals.size(); i++){
            intVal.push_back({intervals[i].start, intervals[i].end});
        }
        sort(intVal.begin(), intVal.end());
        for(int i = 1; i < intVal.size(); i++){
            if(intVal[i-1][1] > intVal[i][0]){
                return false;
            }
        }
        return true;
    }
};
