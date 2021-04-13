/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。*/

/*
解题思路：

本文解法基于性质：二叉搜索树的中序遍历为 递增序列 。
将 二叉搜索树 转换成一个 “排序的循环双向链表” ，其中包含三个要素：

    排序链表： 节点应从小到大排序，因此应使用 中序遍历 “从小到大”访问树的节点。
    双向链表： 在构建相邻节点的引用关系时，设前驱节点 pre 和当前节点 cur ，不仅应构建 pre.right = cur ，也应构建 cur.left = pre 。
    循环链表： 设链表头节点 head 和尾节点 tail ，则应构建 head.left = tail 和 tail.right = head 。


*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:

    Node *pre, *head;

    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        dfs(root);
        head->left = pre; 
        pre->right = head;

        return head;
    }

private:

    void dfs(Node *cur)
    {
        if(cur == nullptr) return;

        /*下面实际上是一个中序遍历的模板*/
/*1*/   dfs(cur->left);
/*************************************************/
/*2*/   cur->left = pre;

        if(pre == nullptr) head = cur;
        else pre->right = cur;

        pre = cur;
/*************************************************/
/*3*/   dfs(cur->right);
    }
};
