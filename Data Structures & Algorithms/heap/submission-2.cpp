class MinHeap {
public:
    MinHeap() {}
    vector<int> heap_;
    void push(int val) {
        heap_.push_back(val);
        int i = heap_.size()-1;
        while(i > 0 && heap_[(i-1)/2] > heap_[i]){
            int m = (i-1)/2;
            swap(heap_[i], heap_[m]);
            i = m;
        }
    }

    int pop() {
        if(heap_.empty()) return -1;
        int val = heap_[0];
        heap_[0] = heap_[heap_.size()-1];
        heap_.pop_back();
        int i = 0;
        while(true){
            int l = i * 2 + 1;
            int r = i * 2 + 2;
            int m = i;
            if(l < heap_.size() && heap_[l] < heap_[m]) m = l;
            if(r < heap_.size() && heap_[r] < heap_[m]) m = r;
            if(m == i) break;
            swap(heap_[m], heap_[i]);
            i = m;
        }
        return val;
    }

    int top() {
        if(heap_.size() == 0) return -1;

        return heap_[0];
    }

    void heapify(const vector<int>& arr) {
        heap_ = arr;
        if(heap_.size() <= 1) return;
        int n = (int)heap_.size();

        for(int i = heap_.size()/2-1; i >= 0;i--){
            int p = i;
            while(true){
                int l = 2 * p + 1;
                int r = 2 * p + 2;
                int m = p;
                if(l < n && heap_[l] < heap_[m]) m = l;
                if(r < n && heap_[r] < heap_[m]) m = r;

                if(m == p) break;
                swap(heap_[m], heap_[p]);
                p = m;
            }
        }
    }
};
