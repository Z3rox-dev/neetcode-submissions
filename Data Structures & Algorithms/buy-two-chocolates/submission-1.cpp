class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int num1 = INT_MAX;
        int num2 = INT_MAX;

        for(int& p : prices){
            if(p < num1){
                if(num1 < num2){
                    num2 = p;
                }
                else{
                    num1 = p;
                }
            }
            else if(p < num2){
                num2 = p;
            }
        }
        if(num1 + num2 > money){
            return money;
        }
        return (money - (num1 + num2));
    }
};