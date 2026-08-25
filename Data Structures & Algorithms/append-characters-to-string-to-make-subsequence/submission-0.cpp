class Solution {
public:
    int appendCharacters(string s, string t) {
        int s1 = 0;
        int t1 = 0;
        while(s1 < s.size() && t1 < t.size()){
            if(s[s1] == t[t1]){
                s1++;
                t1++;
            }
            else{
               s1++; 
            }
        }

        return t.size() - t1;
    }
};