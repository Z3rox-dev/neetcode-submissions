class MovingAverage {
public:
    int cur = 0;
    int size = 0;
    vector<int> vals;
    MovingAverage(int size) : size(size){
        
    }
    
    double next(int val) {
        if(vals.size() == 0){
            vals.push_back((double)val);
            return vals.back();
        }
        vals.push_back(vals.back() + val);
        if(vals.size() > size){
            int idx = vals.size() - size - 1;
            return (double)(vals.back() - vals[idx])/(double)size;
        }
        return vals.back()/(double)vals.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
