#include<bits/stdc++.h>
using namespace std;

// 数组hash表，即 key 和 存储了key、value的数组的index 组成了hash表
template<typename K, typename V>
class MyArrayHashMap{
private:
    class Node {
    private:
        K key;
        V val;
        Node(K key, V val) : key(key), val(val) {}
    };
    unordered_map<K, int> map;
    vector<Node> arr;
    default_random_engine e;

public:
    


};

int main() {

    return 0;
}