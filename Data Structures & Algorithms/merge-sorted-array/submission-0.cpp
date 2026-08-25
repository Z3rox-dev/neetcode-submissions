class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m-1;
        int idx_2 = n-1;
        int writeIdx = m + n - 1;

        while(idx >= 0 && idx_2 >= 0){
            if(nums1[idx] > nums2[idx_2]){
                nums1[writeIdx] = nums1[idx];
                idx--;
            }
            else{
                nums1[writeIdx] = nums2[idx_2];
                idx_2--;
            }
            writeIdx--;
        }

        while(idx >= 0){
            nums1[writeIdx] = nums1[idx];
            idx--;
            writeIdx--;
        }
        while(idx_2 >= 0){
            nums1[writeIdx] = nums2[idx_2];
            idx_2--;
            writeIdx--;
        }
    }
};