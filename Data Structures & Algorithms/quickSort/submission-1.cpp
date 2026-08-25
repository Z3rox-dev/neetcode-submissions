// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    int partition(vector<Pair>& pairs, int left, int right){
        Pair pivot = pairs[right];
        int j = left;
        for(int i = left; i < right; i++){
            if(pairs[i].key < pivot.key){
                auto temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
                j++;
            }
        }

        auto temp = pairs[right];
        pairs[right] = pairs[j];
        pairs[j] = temp;
        return j;
    }

    void divide(vector<Pair>& pairs, int left, int right){
        if(left >= right) return;
        
        int mid = partition(pairs, left, right);
        divide(pairs,left, mid - 1);
        divide(pairs, mid + 1, right);

    }

    vector<Pair> quickSort(vector<Pair>& pairs) {
        divide(pairs, 0, pairs.size()-1);

        return pairs;
    }
};
