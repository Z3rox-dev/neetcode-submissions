class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int> bigger;
        priority_queue<int, vector<int>, greater<int>> smaller;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > x){
                smaller.push(arr[i]);
            }
            else{
                bigger.push(arr[i]);
            }
        }
        vector<int> res;
        while(!bigger.empty() && !smaller.empty()){
            if(smaller.top() - x < x - bigger.top()){
                res.push_back(smaller.top());
                smaller.pop();
            }
            else{
                res.push_back(bigger.top());
                bigger.pop();
            }
            if(res.size() == k){
                sort(res.begin(), res.end());
                return res;
            }
        }

        while(!bigger.empty() && res.size() < k){
            res.push_back(bigger.top());
            bigger.pop();
        }

        while(!smaller.empty() && res.size() < k){
            res.push_back(smaller.top());
            smaller.pop();
        }

        sort(res.begin(), res.end());
        return res;
    }
};