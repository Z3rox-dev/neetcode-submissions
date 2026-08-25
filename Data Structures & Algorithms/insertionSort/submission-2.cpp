// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };

void insertion(int pos, Pair p, vector<Pair>& pairs){
    pairs.push_back(pairs.back());
    for(int i = pairs.size()-1; i > pos; i--){
        pairs[i] = pairs[i-1];
    }
    pairs[pos] = p;
    return;
}

void eraser(int pos, vector<Pair>& pairs){
    for(int i = pos; i < pairs.size()-1; i++){
        pairs[i] = pairs[i+1];
    }
    pairs.pop_back();
    return;
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
            insertion(left, pairs[i], pairs);
            eraser(i + 1, pairs);
            ans.push_back(pairs);
        }
        return ans;
    }
}; 
