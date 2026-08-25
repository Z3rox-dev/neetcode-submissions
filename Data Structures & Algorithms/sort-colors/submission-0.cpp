class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(int& num : nums){
            count[num] += 1;
        }

        int k = 0;
        for(int i = 0; i < 3; i++){
            int iterations = count[i];
            while(iterations > 0){
                nums[k] = i;
                k++;
                iterations--;
            }
        }
    }
};