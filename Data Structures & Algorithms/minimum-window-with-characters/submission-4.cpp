class Solution {
public:
    template<typename Map1, typename Map2>
    bool containAtLeast(const Map1& required, const Map2& avaiable){
        for(const auto& [key, count] : required){
            auto it = avaiable.find(key);
            if(it == avaiable.end() || it->second < count){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        std::string ans = "";
        std::unordered_map<char, int> mapS;
        std::unordered_map<char, int> mapT;
        int stringT_length = t.length();
        if(stringT_length > s.length()){
            return "";
        }

        for(int i = 0; i < stringT_length; i++){
            mapT[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while(right < s.length()){
            mapS[s[right]]++;
            while(containAtLeast(mapT, mapS)){
                if(right - left + 1 < minLen){
                minLen = std::min(minLen, right - left + 1);
                minStart = std::max(minStart, left);
                }
                mapS[s[left]]--;
                if(mapS[s[left]] == 0){
                    mapS.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        if(minLen == INT_MAX) return "";
        for(int i = minStart; i < minStart + minLen; i++){
            ans.push_back(s[i]);
        }

        return ans;
    }
};