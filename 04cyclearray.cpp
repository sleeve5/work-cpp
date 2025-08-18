#include<bits/stdc++.h>
using namespace std;

template<typename T>
class CycleArray{
    vector<T> arr;
    int start;
    int end;
    int count;

    void resize(int newSize){
        vector<T> newArr(newSize);
        if (newSize < count)
        {
            cout << "new size not enough!" << endl;
        }
        for (int i = 0; i < count; i++)
        {
            newArr[i] = arr[(start + i) % arr.size()];
        }
        arr = move(newArr);
        start = 0;
        end = count;
    }

    public:
        CycleArray(): CycleArray(1){}
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

        void addFirst(const T &val){

        }
};

int main(){
    CycleArray<int> arr;

    return 0;
}
