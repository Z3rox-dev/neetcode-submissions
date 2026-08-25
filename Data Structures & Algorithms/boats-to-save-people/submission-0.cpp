class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        //[1,2,4,5]
        int left = 0;
        int right = people.size()-1;
        int k = 0;
        while(left <= right){
            if(people[right] + people[left] <= limit){
                k++;
                right--;
                left++;
            }
            else{
                k+=1;
                right--;
            }
        }
        return k;
        
    }
};