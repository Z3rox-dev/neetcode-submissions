class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        function<bool(int)> canLoad = [&](int mid){
            vector<int> w = weights;
            int rem = days;
            for(int i = 0; i < w.size();){
                int cur = 0;
                if(w[i] > mid){
                    return false;
                }

                while(i < w.size() && cur + w[i] <= mid){
                    cur += w[i];
                    i++;
                }
                rem--;
                if(rem < 0){
                    return false;
                }
            }
            return true;
        };


        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while(left < right){
            int mid = left + (right - left)/2;
            
            if(canLoad(mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};