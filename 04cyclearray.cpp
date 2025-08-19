#include<bits/stdc++.h>
using namespace std;

// 设计左闭右开的环形数组
template<typename T>
class CycleArray {
    vector<T> arr;
    int start;
    int end;
    int count;

    void resize(int newSize) {
        vector<T> newArr(newSize);
        if (newSize < count) {
            cout << "new size not enough!" << endl;
        }
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(start + i) % arr.size()];
        }
        arr = move(newArr);
        start = 0;
        end = count;
    }

public:
    CycleArray(): CycleArray(1) {}
    explicit CycleArray(int size): arr(size), start(0), end(0), count(0) {}
    
    bool isFull() const {
        return count == arr.size();
    }

    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void addLast(const T &val) {
        if (isFull()) {
            resize(arr.size() * 2);
        }
        // 左闭右开，右加，先赋值，再移位
        arr[end] = val;
        end = (end + 1) % arr.size();
        count++;
    }

    void removeLast() {
        if (isEmpty()) {
            throw runtime_error("Array is empty!");
        }
        // 左闭右开，右减，先移位，再赋值
        end = (end - 1 + arr.size()) % arr.size();
        arr[end] = T();
        count--;
        // 缩容，留1/4冗余，防止频繁扩/缩容带来的性能损耗
        if (count > 0 && count == arr.size() / 4) {
            arr.resize(arr.size() / 2);
        }
    }

    void addFirst(const T &val) {
        if (isFull()) {
            resize(arr.size() * 2);
        }
        // 左闭右开，左加，先移位，再赋值
        start = (start - 1 + arr.size()) % arr.size();  // +arr.size()防止负数
        arr[start] = val;
        count++;
    }

    void removeFirst() {
        if (isEmpty()) {
            throw runtime_error("Array is empty!");
        }
        arr[start] = T();
        start = (start + 1) % arr.size();
        count--;
        // 缩容，留1/4冗余，防止频繁扩/缩容带来的性能损耗
        if (count > 0 && count == arr.size() / 4) {
            arr.resize(arr.size() / 2);
        }
    }

    T getFirst() const {
        if (isEmpty()) {
            throw runtime_error("Array is empty!");
        }
        return arr[start];
    }

    T getLast() const {
        if (isEmpty()) {
            throw runtime_error("Array is empty!");
        }
        return arr[(end - 1 + arr.size()) % arr.size()];
    }        
};

int main(){
    CycleArray<int> arr(8);
    arr.addFirst(8);
    arr.addLast(5);
    arr.addLast(9);
    arr.removeFirst();
    cout << arr.getFirst() << endl;
    cout << arr.size() << endl;
    cout << arr.getLast() << endl;

    return 0;
}
