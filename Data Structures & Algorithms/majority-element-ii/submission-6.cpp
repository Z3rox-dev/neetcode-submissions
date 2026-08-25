class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int i = 0;
        int num1 = 0;
        int num2 = 0;
        int j = 0;
        
        for (int k = 0; k < (int)nums.size(); k++) {
            if (nums[k] == num1) {
                i++;
            } else if (nums[k] == num2) {
                j++;
            } else if (i == 0) {
                num1 = nums[k];
                i = 1;
            } else if (j == 0) {
                num2 = nums[k];
                j = 1;
            } else {
                i--;
                j--;
            }
        }

        vector<int> res;
        i = 0;
        j = 0;
        bool found1 = false;
        bool found2 = false;
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] == num1){
                i++;
                if(i > nums.size()/3 && !found1){
                    res.push_back(num1);
                    found1 = true;
                }
            }
            else if(nums[k] == num2){
                j++;
                if(j > nums.size()/3 && !found2){
                    res.push_back(num2);
                    found2 = true;
                }
            }
            if(res.size() == 2){
                return res;
            }
        }
        return res;
    }
};