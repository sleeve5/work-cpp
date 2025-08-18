#include<bits/stdc++.h>
using namespace std;

// 单链表
class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

// 将数组转化为单链表
ListNode* createLinkedList(const vector<int> &arr) {
        if (arr.empty()){
            return nullptr;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* cur = head;
        for(int i = 1; i < arr.size(); i++){
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }

void printList(ListNode* node, string msg){
    cout << endl << msg << endl;
    for(ListNode* p = node; p != nullptr; p = p->next){
        cout << p->val << "  ";
    }
    cout << endl;
}

int main(){
    // 数组转为链表
    vector<int> arr{1, 2, 3, 4, 5};
    ListNode* head =  createLinkedList(arr);
    printList(head, "linked list:");

    // // 头部插入
    // ListNode* headNode = new ListNode(-1);
    // headNode->next = head;
    // head = headNode;
    // printList(head, "linked list adding head:");

    // // 尾部插入
    // ListNode* p = head;
    // for (; p->next != nullptr; ) {
    //     p = p->next;
    // }
    // ListNode* headNode =  new ListNode(7);
    // p->next = headNode;
    // printList(head, "linked list adding tail:");

    // // 中间插入，在第三个节点后面添加666
    // ListNode* p = head;
    // for (int i = 0; i < 2; i++) {
    //     p = p->next;
    // }
    // ListNode* middleNode = new ListNode(666);
    // middleNode->next = p->next;
    // p->next = middleNode;
    // printList(head, "linked list adding after the 3rd:");

    // // 头部删除
    // ListNode* p = head;
    // head = head->next;
    // printList(head, "linked list deleting head:");

    // // 尾部删除
    // ListNode* p = head;
    // for ( ; p->next->next != nullptr;) {
    //     p = p->next;
    // }
    // p->next = nullptr;
    // cout <<  << endl;
    // printList(head, "linked list deleting tail:");

    // // 中间删除，删第四个节点
    // ListNode* p = head;
    // for(int i = 0; i < 2; i++) {
    //     p = p->next;
    // }
    // p->next = p->next->next;
    // printList(head, "linked list deleting the 4th:");

    return 0;
    
}
