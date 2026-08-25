class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        if(s.empty()) return 0;
        if(size == 1) return 1;
        unordered_set<int> mySet;
        int maxLength = 1;
        int right = 1;
        int left = 0;
        mySet.insert(s[left]);

        while(right < size){
            while(mySet.find(s[right]) != mySet.end()){
                mySet.erase(s[left]);
                left++;
            }
            mySet.insert(s[right]);
            right++;

            maxLength = max(maxLength, right - left);
        }
        return maxLength;
    }
};
