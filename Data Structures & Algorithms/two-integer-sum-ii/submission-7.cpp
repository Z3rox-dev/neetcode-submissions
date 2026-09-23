class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        for(int i = 0; i < numbers.size(); i++){
            int num = target - numbers[i];
            if(num > numbers.back()){
                continue;
            }

            int left = i;
            int right = numbers.size()-1;
            while(left <= right){

                int mid = left + (right - left)/2;

                if(numbers[mid] > num){
                    right--;
                }
                else if(numbers[mid] < num){
                    left++;
                }
                else{
                    return {i + 1 , mid + 1};
                }
            }
        }
        return {};
    }
};
