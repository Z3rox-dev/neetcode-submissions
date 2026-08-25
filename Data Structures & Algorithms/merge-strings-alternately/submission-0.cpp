class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int left = 0; int right = 0;
        string res = "";
        while(left < word1.size() && right < word2.size()){
            if(left <= right){
                res+= word1[left];
                left++;
            }
            else{
                res+= word2[right];
                right++;
            }
        }

        while(left < word1.size()){
            res+= word1[left];
            left++;
        }
        while(right < word2.size()){
            res+= word2[right];
            right++;
        }
        return res;
    }
};