class ZigzagIterator {
public:
    int idx1 = 0;
    int idx2 = 0;
    vector<int> v1;
    vector<int> v2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : v1(v1), v2(v2) {
        
    }

    int next() {
        if(idx1 == idx2){
            if(idx1 < v1.size()){
                int val = v1[idx1];
                idx1++;
                return val;
            }
            else{
                if(idx2 < v2.size()){
                    int val = v2[idx2];
                    idx2++;
                    return val;
                }
            }
        }
        else{
            if(idx2 < v2.size()){
                int val = v2[idx2];
                idx2++;
                return val;
            }
            else{
                if(idx1 < v1.size()){
                    int val = v1[idx1];
                    idx1++;
                    return val;
                }
            }    
        }
        return -1;
    }

    bool hasNext() {
       return idx1 < v1.size() || idx2 < v2.size(); 
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
