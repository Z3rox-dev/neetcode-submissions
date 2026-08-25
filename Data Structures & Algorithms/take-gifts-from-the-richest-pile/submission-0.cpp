class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int& g : gifts){
            pq.push(g);
        }

        while(k > 0 && !pq.empty()){
            int temp = pq.top();
            pq.pop();
            temp = floor(sqrt(temp));
            pq.push(temp);
            k--;
        }
        int res = 0;
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            res += temp;
        }
        return res;
    }
};