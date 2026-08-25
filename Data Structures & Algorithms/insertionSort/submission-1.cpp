// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };

void insertion(vector<Pair>& pairs){
    
}
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int vectorSize = pairs.size();
        vector<vector<Pair>> ans;
        for(int i = 0; i < vectorSize; i++){
            int left = 0;
            int right = i;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(pairs[mid].key <= pairs[i].key){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            if(left == i){
                ans.push_back(pairs);
                continue;
            }
            pairs.insert(pairs.begin() + left, pairs[i]);
            pairs.erase(pairs.begin() + i + 1);
            ans.push_back(pairs);
        }
        return ans;
    }
}; 
