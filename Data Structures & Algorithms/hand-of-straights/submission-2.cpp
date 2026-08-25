class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        int groups = hand.size() / groupSize;
        unordered_map<int, int> mp;
        sort(hand.begin(), hand.end());
        for(int i = 0; i < hand.size(); i++){
            mp[hand[i]]++;
        }
        int res = 0;
        while(true){
            int num = INT_MAX;
            int j = 0;
            for(auto n : hand){
                if(mp.find(n) != mp.end()){
                    num = min(num, n);
                }
            }
            while(j < groupSize){
                if(mp.find(num) != mp.end()){
                    mp[num]--;
                    if(mp[num] == 0){
                        mp.erase(num);
                    }
                }
                else{
                    return false;
                }
                j++;
                num++;
            }
            if(j == groupSize){
                res++;
            }
            if(res == groups){
                return true;
            }
        }
        return res == groups;
    }
};
