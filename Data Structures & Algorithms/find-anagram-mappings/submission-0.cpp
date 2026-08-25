class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums2.size(); i++){
            mp[nums2[i]] = i;
        }

        vector<int> mapping;
        for(auto& num : nums1){
            mapping.push_back(mp[num]);
        }
        return mapping;
    }
};
