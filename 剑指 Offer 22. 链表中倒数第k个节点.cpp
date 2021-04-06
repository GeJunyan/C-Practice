/*输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        /*不需要知道链表长度，指针1先走k-1步，然后指针2和指针1同时前进，
        当指针1指向链表最后一个元素时，指针2即为所求。*/

        ListNode * fast = head;
        ListNode * slow = head;

        while(k-1)
        {
            fast = fast->next;
            k--;
        }

        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;

    }
};
