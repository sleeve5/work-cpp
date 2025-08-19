#include<bits/stdc++.h>
using namespace std;

// // hash表基本原理
// class MyHashMap {
//     private:
//         vector<void*> table;
//     public:
//     // 增、改
//     void put(auto key, auto value) {
//         int index = hash(key);
//         table[index] = value;
//     }

//     // 查
//     auto get(auto key) {
//         int index = hash(key);
//         return table[index];
//     }

//     void remove(auto key) {
//         int index = hash(key);
//         table[index] = nullptr;
//     }

//     private:
//         int hash(auto key) {
//             ...
//         }
// };

// 下面实现hash链表
template <typename K, typename V>
class Node {
    public:
        K key;
        V val;
        Node* next;
        Node* prev;
        Node(K key, V val): key(key), val(val), next(nullptr), prev(nullptr) {}
};

template <typename K, typename V>
class Mylinkedhashmap {
private:
    Node<K, V>* head;
    Node<K, V>* tail;
    unordered_map<K, Node<K, V>*> map;

    void addLastNode(Node<K ,V>* node) {
        Node<K, V>* myPrev = tail->prev;
        node->next = tail;
        node->prev = myPrev;
        myPrev->next = node;
        tail->prev = node;
    }

    void removeNode(Node<K, V>* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

public:
    Mylinkedhashmap() {
        // head和tail是dummy哨兵节点，不存储数据
        head = new Node<K, V>(K(), V());
        tail = new Node<K, V>(K(), V());
        head->next = tail;
        tail->prev = head;
    }

    ~Mylinkedhashmap() {
        Node<K, V>* curr = head->next;
        while (curr != tail) {
            Node<K, V>* p = curr->next;
            delete curr;
            curr = p;
        }
        delete head;
        delete tail;
    }

    // 禁用拷贝构造、拷贝赋值
    Mylinkedhashmap(const Mylinkedhashmap&) = delete;
    Mylinkedhashmap& operator=(const Mylinkedhashmap&) = delete;

    size_t size() {
        return map.size();
    }

    bool isEmpty() {
        return map.empty();
    }

    bool existKey(K key) {
        return map.find(key) != map.end();
    }

    vector<K> printKeys() {
        vector<K> keyList;
        for (Node<K, V>* node = head->next; node != tail; node = node->next) {
            keyList.push_back(node->key);
        }
        return keyList;
    }

    V get(K key) {
        if (map.find(key) == map.end()) {
            return V();
        }
        return map[key]->val;
    }

    void put(K key, V val) {
        if (map.find(key) == map.end()) {
            Node<K, V>* node = new Node<K, V>(key, val);
            addLastNode(node);
            map[key] = node;
            return;
        }
        map[key]->val = val;
    }

    void remove(K key) {
        if (map.find(key) == map.end()) {
            return;
        }
        Node<K, V>* node = map[key];
        map.erase(key);
        removeNode(node);
        delete node;
    }
};


int main() {
    Mylinkedhashmap<string, int> myMap;
    myMap.put("a", 1);
    myMap.put("b", 2);
    myMap.put("c", 3);
    myMap.put("d", 4);
    myMap.put("d", 5);  // 已存在，则替换
    for (const auto& key : myMap.printKeys()) {
        cout << key << " ";
    }
    cout << endl;
    cout << myMap.get("d") << endl;
    myMap.remove("c");
    cout << myMap.size();
}
