class Solution {
public:
    int shortestWay(string source, string target) {
        int ans = 0;
        int i = 0;
        while(i < target.size()){
            int start = i;

            for(int j = 0; j < source.size(); j++){
                if(source[j] == target[i]){
                    i++;
                }
            }
            if(start == i) return -1;
            ans++;
        }

        return ans;
    }
};
