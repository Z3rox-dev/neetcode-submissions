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
    void sort(vector<Pair>& pairs, int left, int right, int mid){
        vector<Pair> temp;
        int k = 0;
        int i = left;
        int j = mid + 1;
        while(i <= mid && j <= right){
            if(pairs[i].key > pairs[j].key){
                temp.push_back(pairs[j]);
                j++;
                k++;
            }
            else{
                temp.push_back(pairs[i]);
                i++;
                k++;
            }
        }
        while(i <= mid){
            temp.push_back(pairs[i]);
            i++;
            k++;
        }
        while(j <= right){
            temp.push_back(pairs[j]);
            j++;
            k++;
        }

        for(int m = 0; m < temp.size(); m++){
            pairs[left + m] = temp[m];
        }
    }

    void merge(vector<Pair>& pairs, int left, int right){
        if(left < 0 || right >= (int)pairs.size() || left >= right) return;

        int mid = (left + right) / 2;
        merge(pairs, left, mid);
        merge(pairs, mid + 1, right);

        sort(pairs, left, right, mid);
    }
    
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        merge(pairs, 0, (int)pairs.size()-1);
        return pairs;
    }
};
