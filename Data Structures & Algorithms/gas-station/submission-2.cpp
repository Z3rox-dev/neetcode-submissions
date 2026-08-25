class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if(totalGas < totalCost) return -1;
        int n = gas.size();
        int cur =  0;
        int start = 0;

        for(int i = 0; i < n; i++){
            cur += gas[i] - cost[i];
            if(cur < 0){
                cur = 0;
                start = i + 1;
            }
        }

        return start;
    }

};
