class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1 && flowerbed[0] == 0 && n <= 1) return true;
        int cnt = 0;
        for(int i = 1; i < flowerbed.size(); ){
            if(i == 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0){
                cnt++;
                i+=2;
            }
            if(flowerbed[i] == 1){
                i += 2;
            }
            else if(i == flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0){
                cnt++;
                break;
            }
            else if(i < flowerbed.size() - 1 < flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                i += 2;
                cnt++;
            }
            else{
                i++;
            }
        }
        return cnt >= n;
    }
};