class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(int i = digits.size()-1; i >= 0; i--){
            if(digits[i] + 1 > 9){
                digits[i] = 0;
                if(i == 0){
                    vector<int> temp = {1};
                    for(int j = 0; j < digits.size(); j++){
                        temp.push_back(digits[j]);
                    }
                    return temp;
                }
            }
            else{
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        return digits;
    }
};
