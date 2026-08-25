class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        for(int i = 0; i < mat[0].size(); i++){
            int target = mat[0][i];
            bool ok = true;

            for(int j = 1; j < mat.size(); j++){
                int left = 0;
                int right = mat[j].size()-1;
                bool found = false;

                while(left <= right){
                    int mid = left + (right - left)/2;
                    
                    if(mat[j][mid] > target){
                        right = mid - 1;
                    }
                    else if(mat[j][mid] < target){
                        left = mid + 1;
                    }
                    else{
                        found = true;
                        break;
                    }
                }
                if(!found){
                    ok = false;
                }
            }
            if(ok){
                return target;
            }
        }
        return -1;
    }
};
