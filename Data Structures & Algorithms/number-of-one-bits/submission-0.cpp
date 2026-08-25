class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) return 0;

        int res = 0;
        while(n > 0){
             res += (n & 1);
             n >>= 1;
        }
        return res;
    }
};
