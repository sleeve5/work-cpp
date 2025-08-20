#include<bits/stdc++.h>
using namespace std;

// 数组hash表，即 key 和 存储了key、value的数组的index 组成了hash表
template<typename K, typename V>
class MyArrayHashMap{
private:
    class Node {
    public:
        K key;
        V val;
        Node(K key, V val) : key(key), val(val) {}
    };
    unordered_map<K, int> map;
    vector<Node> arr;
    default_random_engine e;

public:
    MyArrayHashMap() {
        random_device rd;
        auto seed = rd();
        e.seed(seed);
    }

    bool existKey(K key) {
        return map.count(key);
    }

    int size() {
        return arr.size();
    }

    V get(K key) {
        if (!existKey(key)) {
            return V();
        }
        int index = map[key];
        return arr[index].val;
    }

    void put(K key, V val) {
        if (existKey(key)) {
            int index = map[key];
            arr[index].val = val;
            return;
        }
        arr.push_back(Node(key, val));
        map[key] = arr.size() - 1;
    }

    void remove(K key) {
        if (!existKey(key)) {
            return;
        }
        int index = map[key];

        swap(arr[index], arr.back());
        map[arr[index].key] = index;
        arr.pop_back();
        map.erase(key);
    }

    K randomKey() {
        uniform_int_distribution<int> u(0, arr.size() - 1);
        int randomIndex = u(e);
        return arr[randomIndex].key;
    }
};

int main() {
    MyArrayHashMap<int, int> map;
    map.put(1, 1);
    map.put(2, 2);
    map.put(3, 3);
    map.put(4, 4);
    map.put(5, 5);

    cout << map.get(1) << endl;
    cout << map.randomKey() << endl;

    map.remove(4);
    cout << map.randomKey() << endl;
    cout << map.randomKey() << endl;

    return 0;
}