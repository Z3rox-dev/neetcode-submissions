class MedianFinder {
public:
    priority_queue<int> pqLow;
    priority_queue<int, vector<int>, greater<int>> pqHigh;
    int size = 0;
    MedianFinder() {}
    
    void addNum(int num) {
        if(pqLow.empty()){
            pqLow.push(num);
            return;
        }

        if(pqHigh.empty()){
            if(num < pqLow.top()){
                pqHigh.push(pqLow.top());
                pqLow.pop();
                pqLow.push(num);
                return;
            }
            else{
                pqHigh.push(num);
                return;
            }
        }

        if(num < pqLow.top()){
            pqLow.push(num);
        }
        else{
            pqHigh.push(num);
        }

        if(static_cast<int>(pqLow.size() - pqHigh.size()) >= 2){
            pqHigh.push(pqLow.top());
            pqLow.pop();
        }
        else if(static_cast<int>(pqHigh.size() - pqLow.size()) >= 2){
            pqLow.push(pqHigh.top());
            pqHigh.pop();
        }
    }
    
    double findMedian() {
        if(pqHigh.size() == pqLow.size()){
            return (pqLow.top() + pqHigh.top()) / 2.0;
        }
        if(pqHigh.size() > pqLow.size()){
            return pqHigh.top();
        }

        return pqLow.top();
    }
};
