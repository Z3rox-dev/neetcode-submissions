
class DynamicArray {
public:
    int* arr;
    int capacity;
    int length;

    DynamicArray(int capacity) {
        this->capacity = capacity;
        length = 0;
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(getSize() >= getCapacity()) { resize(); }
        
        set(length, n);
        length++;
        
    }

    int popback() {
        length--;
        return arr[length];
    }

    void resize() {
        int oldCap = capacity;
        capacity = getCapacity() * 2;
        int* temp = arr;
        arr = new int[capacity];
        for(int i = 0; i < oldCap; i++){
           arr[i] = temp[i]; 
        }
        delete[] temp;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
