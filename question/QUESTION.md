# 刷题总结

## 链表

链表通过每个节点上的```next, prev```指针，将零散的内存块串联起来形成一个链式结构。

```cpp
class ListNode {
    public:
        int val;
        ListNode *next; 
        ListNode(int x) : val(x), next(NULL) {}
};
```

### 题型分类

方法根本目的：

- 空间上：不多创建链表
- 时间上：实现一次遍历找到所需节点

注意事项：

- 考虑使用虚拟头节点的时机
- 在遍历时注意```next```指针的循环结束判断，勿访问空指针

#### 链表的分合

当需要创造新链表时，注重虚拟头节点法的使用：可以使用虚拟头结点简化边界情况的处理。尤其用于链表的分解、合并类题目。

- [86.分隔链表](https://leetcode.cn/problems/partition-list/ "86.分隔链表")
- [82.删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/ "82.删除排序链表中的重复元素")（删除元素就是分解链表）


- [21.合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/ "21.合并两个有序链表")
- [23.合并 K 个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/ "23.合并 K 个升序链表")
- [378.有序矩阵中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/ "378.有序矩阵中第 K 小的元素")
- [373.查找和最小的 K 对数字](https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/ "373.查找和最小的 K 对数字")
- [2.两数相加](https://leetcode.cn/problems/add-two-numbers/ "2.两数相加")
- [445.两数相加Ⅱ](https://leetcode.cn/problems/add-two-numbers-ii/ "445.两数相加Ⅱ")

#### 双指针法

两个指针步长一致，在同位置不同时释放[19]，或者同时不同位置释放[160]。

- [19.删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/ "19.删除链表的倒数第 N 个结点")
- [160.相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/ "160.相交链表")
- ~~[82.删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/ "82.删除排序链表中的重复元素")~~


#### 快慢指针法

两指针步长不一致，同时同位置释放。

- [876.链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list/ "876.链表的中间结点")
- [142.环形链表 Ⅱ](https://leetcode.cn/problems/linked-list-cycle-ii/ "142.环形链表 Ⅱ")


