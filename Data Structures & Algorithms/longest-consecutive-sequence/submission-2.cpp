class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> setInt;
        for (const int& num : nums){
            setInt.insert(num);
        }

        int max = 0;
        for(auto num : setInt){
            if (setInt.find(num - 1) == setInt.end()){
             int currentNum = num;
             int currentCount = 1;
                while(setInt.find(currentNum +1) != setInt.end()){
                    currentCount++;
                    currentNum += 1;
                    }
                max = std::max(max, currentCount);
            }
        }
    return max;  
    }
};
