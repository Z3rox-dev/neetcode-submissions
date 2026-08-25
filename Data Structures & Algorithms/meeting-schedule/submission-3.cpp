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
        auto comparator = [](const Interval& a, const Interval& b){
            return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), comparator);

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i-1].end > intervals[i].start){
                return false;
            }
        }
        return true;
    }
};
