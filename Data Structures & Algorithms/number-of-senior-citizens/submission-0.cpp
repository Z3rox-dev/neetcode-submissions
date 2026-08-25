class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(auto s : details){
            int num = stoi(s.substr(11, 2));
            if(num > 60){
                res++;
            }
        }
        return res;
    }
};