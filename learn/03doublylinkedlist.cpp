#include<bits/stdc++.h>
using namespace std;

// 双链表
class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x): val(x), next(nullptr), prev(nullptr) {}
};

// 数组转双链表
DoublyListNode* createDoublyListNode(const vector<int>& arr) {
    if (arr.size() == 0) {
        return nullptr;
    }
    DoublyListNode* head = new DoublyListNode(arr[0]);
    DoublyListNode* cur = head;
    for (int i = 1; i < arr.size(); i++) {
        DoublyListNode* newNode = new DoublyListNode(arr[i]);
        cur->next = newNode;
        newNode->prev = cur;
        cur = cur->next;
    }
    return head;
}

// 正向打印双链表
void printListForward(DoublyListNode* headNode, string msg) {
    cout << endl << msg << endl;
    for (DoublyListNode* p = headNode; p != nullptr; p = p->next) {
        cout << p->val << "  ";
    }
    cout << endl;
}

// 反向打印双链表
void printListBackward(DoublyListNode* tailNode, string msg) {
    cout << endl << msg << endl;
    for (DoublyListNode* p = tailNode; p != nullptr; p = p->prev) {
        cout << p->val << "  ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    DoublyListNode* head =  createDoublyListNode(arr);
    DoublyListNode* tail = head;
    for (; tail->next != nullptr; ) {
        tail = tail->next;
    }
    printListForward(head, "doubly linked list:");
    printListBackward(tail, "reversed doubly linked list:");
    
    // 头部插入
    DoublyListNode* headNode = new DoublyListNode({0});
    headNode->next = head;
    head->prev = headNode;
    head = headNode;
    printListForward(head, "doubly linked list adding head:");

    // 尾部插入
    DoublyListNode* newNode = new DoublyListNode({6});
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    printListForward(head, "doubly linked list adding tail:");

    // 中间插入，在第三个节点后插入666
    DoublyListNode* newNode = new DoublyListNode({666});
    DoublyListNode* p = head;
    for (int i = 0; i < 2; i++){
        p = p->next;
    }
    // 先组装好新节点的prev，next，再插入到原节点之中
    newNode->prev = p;
    newNode->next = p->next;
    p->next = newNode;
    p->next->prev = newNode;
    printListForward(head, "doubly linked list adding after the 3rd:");

    // 头部删除
    DoublyListNode* toDelete = head;
    head->next->prev = nullptr;
    head = head->next;
    toDelete->prev = nullptr; // 释放原head的next
    printListForward(head, "doubly linked list deleting head:");

    // 尾部删除
    DoublyListNode* toDelete = tail;
    tail->prev->next = nullptr;
    tail = tail->prev;
    toDelete->prev = nullptr;
    printListBackward(tail, "reversed doubly linked list deleting tail:");

    // 中间删除，删除第四个节点
    DoublyListNode* p = head;
    for (int i = 0; i < 2; i++) {
        p = p->next;
    }
    DoublyListNode* toDelete = p->next;
    p->next = toDelete->next;
    toDelete->next->prev = p;
    toDelete->next = nullptr; // 释放被删节点的前后指针
    toDelete->prev = nullptr;
    printListForward(head, "doubly linked list deleting the 4th:");
    
    return 0;
}
