class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> profit;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> cp;

        for(int i = 0; i < capital.size(); i++){
            cp.emplace(capital[i], profits[i]);
        }

        while(k--){
            while(!cp.empty() && w >= cp.top().first){
                profit.emplace(cp.top().second);
                cp.pop();
            }
            if(profit.empty()){
                return w;
            }
            w += profit.top();
            profit.pop();
        }
        return w;
    }
};