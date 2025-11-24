/*
 * @lc app=leetcode.cn id=622 lang=cpp
 * @lcpr version=30304
 *
 * [622] 设计循环队列
 */

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode *next) : val(x), next(next) { }
};

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { }
};

// @lc code=start
template<typename E>
class ArrayQueue{
private:
    int size;
    std::vector<optional<E>> data;
    static const int INIT_CAP = 2;
    int first, last;

    void resize(int newCap) {
        std::vector<std::optional<E>> tmp(newCap);
        for (int i = 0; i < size; i++) {
            tmp[i] = data[(first + i) % data.size()];
        }
        first = 0;
        last = size;
        data = std::move(tmp);
    }

public:
    ArrayQueue(int initCap) : size(0), data(initCap), first(0), last(0) {}

    ArrayQueue() : ArrayQueue(INIT_CAP){}

    void enqueue(E e) {
        if (size == data.size()) {
            resize(size * 2);
        }

        data[last] = e;
        last++;
        if (last == data.size()) {
            last = 0;
        }

        size++;
    }

    E dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }

        if (size == data.size() / 4) {
            resize(data.size() / 2);
        }

        E oldVal = *data[first];
        data[first].reset();
        first++;
        if (first == data.size()) {
            first = 0;
        }

        size--;
        return oldVal;
    }

    E peekFirst() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }
        return *data[first];
    }

    E peekLast() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }
        if (last == 0) {
            return *data[data.size() - 1];
        }
        return *data[last - 1];
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

class MyCircularQueue {
private:
    ArrayQueue<int> q;
    int maxCap;

public:
    MyCircularQueue(int k) : q(k), maxCap(k) {}
    
    bool enQueue(int value) {
        if (q.getSize() == maxCap) {
            return false;
        }
        q.enqueue(value);
        return true;
    }
    
    bool deQueue() {
        if (q.isEmpty()) {
            return false;
        }
        q.dequeue();
        return true;
    }
    
    int Front() {
        if (q.isEmpty()) {
            return -1;
        }
        return q.peekFirst();
    }
    
    int Rear() {
        if (q.isEmpty()) {
            return -1;
        }
        return q.peekLast();
    }
    
    bool isEmpty() {
        return q.isEmpty();
    }
    
    bool isFull() {
        return q.getSize() == maxCap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end





/*
// @lcpr case=start
// ["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]\n[[3],[1],[2],[3],[4],[],[],[],[4],[]]\n
// @lcpr case=end

 */

