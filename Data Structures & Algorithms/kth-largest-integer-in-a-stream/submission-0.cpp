class KthLargest {
public:
    int k;
    std::vector<int> vecNums;
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

    KthLargest (int k, std::vector<int>& nums) : k(k), vecNums(nums.begin(), nums.end()) {
        for(const int& num : nums){
            add(num);
        }
    }

    int add(int val) {
        queue.push(val);
        if(queue.size() >k){
            queue.pop();
        }
        return queue.top();
    }
};
