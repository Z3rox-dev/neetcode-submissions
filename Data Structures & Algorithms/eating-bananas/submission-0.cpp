class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int slow = 1;
        int fast = *max_element(piles.begin(), piles.end());
        int total = 0;
        int ans = 0;
        while(slow <= fast){
            int speed = slow + (fast-slow)/2;

            for(int& bananas : piles){
                total += (bananas + speed -1) /(speed);
            }

            if(total > h){
                slow = speed + 1;
            }
            else{
                ans = speed;
                fast = speed - 1;
            }
            total = 0;
        }
        return ans;
    }
};
