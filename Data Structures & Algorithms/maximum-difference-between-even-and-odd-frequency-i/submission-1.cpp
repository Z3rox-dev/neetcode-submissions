class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for(char& c : s){
            mp[c]++;
        }

        int minOdd = s.size();
        int maxOdd = 0;
        int minEven = s.size();
        int maxEven = 0;
        for(auto& [key, value] : mp){
            if(value % 2 == 1){
                if(minOdd > value){
                    minOdd = value;
                }
                if(maxOdd < value){
                    maxOdd = value;
                }
            }
            else if(value % 2 == 0){
                if(minEven > value){
                    minEven = value;
                }
                if(maxEven < value){
                    maxEven = value;
                }
            }
        }

        return max((maxOdd - minEven), (minOdd - maxEven));
    }
};