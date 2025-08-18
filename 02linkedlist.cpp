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
ListNode* createLinkedList(std::vector<int> arr) {
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

int main(){
    // 数组转为链表
    vector<int> arr{1, 2, 3, 4, 5};
    ListNode* head =  createLinkedList(arr);
    cout << "linked list:" << endl;
    for (ListNode* p = head; p != nullptr; p = p->next){
        cout << p->val << "  ";
    }
    cout << endl;

    // // 头部插入
    // ListNode* headNode = new ListNode(-1);
    // headNode->next = head;
    // head = headNode;
    // cout << "linked list adding head:" << endl;
    // for (ListNode* p = head; p != nullptr; p = p->next){
    //     cout << p->val << "  ";
    // }
    // cout << endl;

    // // 尾部插入
    // ListNode* p = head;
    // for (; p->next != nullptr; ) {
    //     p = p->next;
    // }
    // ListNode* headNode =  new ListNode(7);
    // p->next = headNode;
    // cout << "linked list adding tail:" << endl;
    // for (ListNode* p = head; p != nullptr; p = p->next){
    //     cout << p->val << "  ";
    // }
    // cout << endl;

    // // 中间插入，在第三个节点后面添加666
    // ListNode* p = head;
    // for (int i = 0; i < 2; i++) {
    //     p = p->next;
    // }
    // ListNode* middleNode = new ListNode(666);
    // middleNode->next = p->next;
    // p->next = middleNode;
    // cout << "linked list adding middle:" << endl;
    // for (ListNode* p = head; p != nullptr; p = p->next){
    //     cout << p->val << "  ";
    // }
    // cout << endl;

    // // 头部删除
    // ListNode* p = head;
    // head = head->next;
    // cout << "linked list deleting head:" << endl;
    // for (ListNode* p = head; p != nullptr; p = p->next){
    //     cout << p->val << "  ";
    // }
    // cout << endl;

    // // 尾部删除
    // ListNode* p = head;
    // for ( ; p->next->next != nullptr;) {
    //     p = p->next;
    // }
    // p->next = nullptr;
    // cout << "linked list deleting tail:" << endl;
    // for (ListNode* p = head; p != nullptr; p = p->next){
    //     cout << p->val << "  ";
    // }
    // cout << endl;

    // // 删除，删第四个节点
    // ListNode* p = head;
    // for(int i = 0; i < 2; i++) {
    //     p = p->next;
    // }
    // p->next = p->next->next;
    // cout << "linked list deleting the 4th:" << endl;
    // for (ListNode* p = head; p != nullptr; p = p->next){
    //     cout << p->val << "  ";
    // }
    // cout << endl;
    return 0;
    
}

