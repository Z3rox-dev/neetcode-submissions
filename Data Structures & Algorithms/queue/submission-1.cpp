class Deque {
public:

    std::list<int> q;
    Deque() {}

    bool isEmpty() {
        return q.empty();
    }

    void append(int value) {
        q.emplace_back(value);
    }

    void appendleft(int value) {
        q.emplace_front(value);
    }

    int pop() {
        if(isEmpty()) return -1;
        int temp = q.back();
        q.pop_back();

        return temp;

    }

    int popleft() {
        if(isEmpty()) return -1;
        int temp = q.front();
        q.pop_front();
        return temp;
    }
};
