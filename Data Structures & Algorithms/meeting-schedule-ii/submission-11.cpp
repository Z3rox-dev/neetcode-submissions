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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        auto cmp = [](const Interval& a, const Interval& b){
            return a.start < b.start;
        };
        int idx = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        int rooms = 0;

        while(idx < intervals.size()){
            while(!pq.empty() && pq.top() <= intervals[idx].start){
                pq.pop();
            }
            pq.push(intervals[idx].end);
            idx++;

            rooms = max(rooms, (int)pq.size());
        }
        return rooms;
    }
};
