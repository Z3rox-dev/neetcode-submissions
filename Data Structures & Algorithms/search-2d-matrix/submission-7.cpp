class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        int m = matrix[0].size()-1;

        while(left <= right){
            int mid = (left + right)/2;

            if(target >= matrix[mid][0] && target <= matrix[mid][m]){
                int i = 0;
                int j = matrix[mid].size()-1;
                while(i <= j){
                    int center = i + (j - i)/2;

                    if(matrix[mid][center] == target){
                        return true;
                    }
                    else if(matrix[mid][center] < target){
                        i = center + 1;
                    }
                    else{
                        j = center - 1;
                    }
                }
            }

            if(matrix[mid][m-1] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }
};
