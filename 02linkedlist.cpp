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
    vector<int> arr{0, 1, 2, 5, 6};
    ListNode* head =  createLinkedList(arr);
    for (ListNode* p = head; p != nullptr; p = p->next){
        cout << p->val << endl;
    }
    return 0;
}

