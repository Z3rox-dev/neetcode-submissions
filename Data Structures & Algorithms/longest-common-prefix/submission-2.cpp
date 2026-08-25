class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string start = strs[0];
        for(string& str: strs){
            if(str.size() == 0) return "";
            if(str.size() < start.size()){
                start = str;
            }
        }

        for(int i = 0; i < strs.size(); i++){
            int idx = 0;
            int size = start.size();
            for(int j = 0; j < size; j++){
                if(start[j] == strs[i][j]){
                    idx++;
                }
                else{
                    break;
                }
            }
            start = start.substr(0, idx);
        }

        return start;
    }
};