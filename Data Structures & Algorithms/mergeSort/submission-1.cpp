// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };

#include <vector>
#include <string>
using namespace std;

void mergeHalves(vector<Pair>& pairs, int left, int mid, int right){
    int i = left;
    int j = mid;
    vector<Pair> tmp;

    while(i < mid && j < right){
        if(pairs[i].key <= pairs[j].key){
            tmp.push_back(pairs[i]);
            i++;
        }
        else{
           tmp.push_back(pairs[j]);
           j++;
        }
    }

    while(i < mid){
        tmp.push_back(pairs[i]);
        i++;
    }
    while(j < right){
        tmp.push_back(pairs[j]);
        j++;
    }
  
    for(int k = 0; k < tmp.size(); k++){
        pairs[left + k] = tmp[k];
    } 
}

void merge(vector<Pair>& pairs, int left, int right){
    if(right - left <= 1){
        return;
    }
    int mid = left + (right-left)/2;

    merge(pairs, left, mid);
    merge(pairs, mid, right);
    mergeHalves(pairs, left, mid, right);
}

class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        int left = 0;
        int right = pairs.size();
        merge(pairs, left, right);
        return pairs;
    }
};
