// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };

int partition(vector<Pair>& pairs, int left, int right){
    auto pivot = pairs[right];
    int i = left;
    for(int j = left; j < right; j++){
        if(pairs[j].key < pivot.key){
            swap(pairs[j], pairs[i]);
            i++;  
        }
    }
    swap(pairs[i], pairs[right]);
    return i;
}

void quick(vector<Pair>& pairs, int left ,int right){
    if(left >= right){
        return;
    }
    int pivot = partition(pairs, left, right);
    quick(pairs, left, pivot - 1);
    quick(pairs, pivot + 1, right);
}

class Solution {
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quick(pairs,0, pairs.size()-1);
        return pairs;
    }
};
